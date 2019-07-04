/* nanoklogd - forward kernel messages to /dev/log.  */

/* Written by Christian Neukirchen <chneukirchen@gmail.com>
   To the extent possible under law, the creator of this work has waived
   all copyright and related or neighboring rights to this work.  */

/* This uses /dev/log directly because glibc syslog(3) does
   forward LOG_KERN as LOG_USER.  */

#include <sys/klog.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>

static const struct {
        short sun_family;
        char sun_path[9];
} log_addr = {
        AF_UNIX,
        "/dev/log"
};

int
main(int argc, char *argv[]) {
	char buf[16384];
	int f, l, start;
	int stop = 0;

	f = socket(AF_UNIX, SOCK_DGRAM|SOCK_CLOEXEC, 0);
	if (f < 0)
		return 111;

	if (connect(f, (void *)&log_addr, sizeof log_addr) < 0)
		return 112;

	while (1) {
		l = klogctl(2, buf, sizeof buf);
		if (l < 0)
			return 113;

		for (start = 0; start < l; start = stop+1) {
			for (stop = start+1; stop < l && buf[stop] != '\n'; stop++)
				;

			while (send(f, buf+start, stop-start, 0) != stop-start) {
				switch (errno) {
				case ECONNREFUSED:
				case ECONNRESET:
				case ENOTCONN:
					/* syslogd went down, retry until up.  */
					close(f);
					sleep(1);
					f = socket(AF_UNIX, SOCK_DGRAM|SOCK_CLOEXEC, 0);
					if (f < 0)
						return 111;
					connect(f, (void *)&log_addr, sizeof log_addr);
					break;
				default:
					return 114;
				}
			}
		}
	}
	return 0;
}

