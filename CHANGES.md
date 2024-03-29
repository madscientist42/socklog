socklog 2.2.0 
Wed, 03 Mar 2019 19:30:00 CST
  * Resurrected this to be buildable as a clean cross compile
    just like runit was done a bit under two years ago now.
  * Moved to a CMake based build system for that purpose.
  * Did a similar restructure of the directories to make this
    more maintainable.
  * Added nanoklogd from Void's build out for this package to
    this as it properly belongs in here as far as I'm concerned.

socklog 2.1.0
Mon, 06 Mar 2006 12:59:33 +0000
  * socklog-conf, man/socklog-conf.8: create service directories
    /etc/sv/socklog-* instead of /etc/socklog/*; create ./check script
    for socklog-unix service.
  * doc/configuration.html, doc/install.html, doc/network.html,
    doc/notify.html: adapt to new path to service directories; utilize
    runit's sv program instead of runsvctrl.
  * man/socklog-check.8, man/socklog-conf.8, man/socklog.8, man/uncat.1:
    see also sv(8).

socklog 2.0.3
Sun, 26 Feb 2006 13:29:17 +0000
  * doc/index.html: minor.
  * socklog-check.c: change EDESTADDRREQ to ECONNREFUSED if defined and set
    by connect().
  * tryto: fix a race with child terminating immediatly (thx Alex Efros);
    catch SIGCHLD while waiting ktimeout seconds before sending KILL.
  * man/tryto.1: remove reference to timelimit(8) (thx Alex Efros).
  * socklog.check, socklog.dist: don't check usage output with -V as it
    differs on solaris (thx Asif Iqbal).

socklog 2.0.2
Sun, 10 Apr 2005 07:21:30 +0000
  * doc/readme.solaris.html: add -ldoor -lthread to src/conf-ld (thx Lars
    Kellogg-Stedman); update log/run script, mailing list address.
  * man/socklog.8: remove double entries in SEE ALSO.

socklog 2.0.1
Thu, 10 Feb 2005 10:05:55 +0000
  * Makefile: add linker options detected by trysocketlib.c to targets
    check-socklog-inet, check-socklog-inet (fixes test failure on solaris,
    thx Uffe Jakobsen).

socklog 2.0.0
Sun, 06 Feb 2005 19:57:04 +0000
  * socklog-check.check: tweak timing in program test.
  * tryto.c: new option -P: run prog in new session, and signal process
    group.
  * man/tryto.1: adapt; cleanup.
  * man/socklog-check.8: add hint about runit services using syslog
    facility; cleanup.
  * man/socklog-conf.8, man/socklog.8, man/uncat.1: cleanup.
  * doc/index.html: new stable release.
  * doc/network.html: typo.

socklog 1.5.0
Sat, 26 Jun 2004 11:28:33 +0000
  * socklog-check, man/socklog-check.8: new; check for the availability of
    a socklog service.
  * socklog-check.check, socklog-check.dist: new; program test.
  * byte_zero.c: new.
  * socklog.c, man/socklog.8: new option -U: don't override umask when
    creating domain socket.
  * package/check, package/compile, package/install-man, package/upgrade:
    minor cleanup.
  * Makefile, man/socklog-conf.8: adapt.

socklog 1.4.2
Tue, 23 Mar 2004 18:16:17 +0000
  * doc/index.html, doc/install.html: minor.
  * socklog.c: fix sigterm handling in ucspi mode.
  * uncat.check: tweak timing in program test.
  * Makefile: don't run target check by default.
  * package/check: new; run checks on programs.
  * package/install: run package/check.

socklog 1.4.1
Sat, 28 Feb 2004 17:47:13 +0000
  * socklog.c: handle sigterm on other platforms as accurately as already
    done on solaris.
  * tryto.c, uncat.c: minor cleanup.
  * check-diff, check-dist, check-local: new; run checks on programs.
  * socklog-conf.check, socklog.check, tryto.check, uncat.check,
    check-socklog-inet.c, check-socklog-unix.c: new; check program.
  * socklog-conf.dist, socklog.dist, tryto.dist, uncat.dist: new; dist check
    program output.
  * package/COPYING: 2004.
  * package/compile, package/install-man, package/upgrade: minor.

socklog 1.3.1
Mon, 19 Jan 2004 18:39:01 +0000
  * trysocketlib.c: new; check for libraries needed for socket() on some
    systems (solaris, thx Uffe Jakobsen).
  * Makefile: adapt.
  * socklog.c, socklog-conf.c: add defines automatically detecting solaris
    systems; now builds on solaris out-of-the-box (thx Uffe Jakobsen, Lars
    Uffmann).
  * doc/readme.solaris.html: adapt (thx Lars Uffmann).
  * print-cc.sh, print-ld.sh: head -1 -> head -n1.

socklog 1.3.0
Mon, 12 Jan 2004 19:06:56 +0000
  * socklog.c: add getopt-style command line options -r, -R for logging raw
    syslog messages without priority, facility conversion.
  * man/socklog.8: adapt.
  * doc/network.html: document old-style syslog network logging through UDP.
  * doc/index.html: change short description.
  * package/compile, package/install-man, package/upgrade: exit 1 on
    sub-shell failures.

socklog 1.2.0
Sat, 09 Aug 2003 18:08:20 +0200
  * socklog-conf.c: fix run file for socklog-unix service on solaris; use
    runit's chpst instead of setuidgid.
  * doc/install.html: remove obsolete note about setuidgid replacement.
  * doc/examples.html: adapt.
  * doc/index.html: adapt examples.
  * doc/benefits.html: minor.

socklog 1.1.1
Mon, 07 Jul 2003 09:59:08 +0200
  * socklog-conf.c: fix typos (thx Hleil Liu); use mail -s instead of
    mailsubj for the notify service.

socklog 1.1.0
Thu, 19 Jun 2003 15:40:52 +0200
  * man/socklog-conf.8, man/socklog.8, man/tryto.1: typos.
  * doc/benefits.html, doc/configuration.html, doc/examples.html,
    doc/index.html, doc/network.html, doc/notify.html,
    doc/readme.solaris.html, man/socklog-conf.8, man/socklog.8, man/tryto.1,
    man/uncat.1: utilize runit package instead of daemontools package.
  * socklog-conf.c: create service directories for the use with the runit
    package.

socklog 1.0.0
Thu, 30 Jan 2003 13:32:24 +0100
  * doc/configuration.html, doc/examples.html: remove description for
    socklog-ucspi-unix service.
  * doc/benefits.html, doc/network.html, doc/readme.solaris.html,
    doc/usedietlibc.html, man/socklog-conf.8: typos.
  * error.h: include <errno.h>.
  * tryto.c: catch possible error in write() to child; minor cleanup.
  * doc/index.html: add NetBSD to supported systems.

socklog 0.10.1
Thu, 08 Aug 2002 22:55:35 +0200
  * package/versions: new.
  * doc/network.html: typos.
  * doc/usedietlibc.html: fix path to conf-cc, conf-ld.

socklog 0.10.0
Thu, 18 Jul 2002 15:45:58 +0200
  * solaris support rewrite (thx Lars Uffmann):
    * socklog.c: new option sun_stream; new optional option door; rewrite
      solaris related code.
    * socklog-conf.c: option unix: create special run script on solaris.
    * doc/readme.solaris.html: new.
    * (thx Lars Uffmann).
  * documentation adapted.

socklog 0.9.1
Wed, 26 Jun 2002 15:54:06 +0200
  * Makefile: enable target sysdeps.

socklog 0.9.0
Fri, 31 May 2002 14:07:11 +0200
  * new service socklog-klog doing kernel logging.
  * socklog.c: fix facility and priority decoding in ucspi mode.
  * socklog-conf.c: creates socklog-klog's service directories.
  * doc/configuration.html, doc/examples.html, man/socklog-conf.8: document
    socklog-klog service.

socklog 0.8.2
Sat, 18 May 2002 15:08:09 +0200
  * src/: include public domain sources to build byte.a, unix.a, time.a:
    socklog builds without having daemontools' sources installed.
  * doc/usedietlibc.html: how to use dietlibc.

socklog 0.8.1
Sun, 28 Apr 2002 10:32:28 +0200
  * tryto.c: change return value on child timeout to 100, add FATAL prefix
    to error message on child timeout/crash.

socklog 0.8.0
Tue, 16 Apr 2002 14:11:34 +0200
  * doc/network.html: fix quoting bug, network client sample was not
    working properly.
  * doc/benefits.html: add more descriptions of benefits.
  * no code changes at all.

socklog 0.7.0
Mon,  4 Feb 2002 11:37:13 +0100
  * install-man: symlinks now point into the correct directory:
    /package/admin/socklog/man/ (thx Mike Forster).
  * socklog.c: complete revision: dropped fdbuffer.o, switched to unix.a,
    byte.a support libraries (now in the Public domain).
  * socklog-conf.c: support log dir with cross device link; optional logdir
    option must start with /.
  * Makefile: sysdeps.
  * doc: revised.
  * (thx Gary Gendel, support for solaris)

socklog 0.6.1
Thu, 17 Jan 2002 11:43:36 +0100
  * bug: socklog.c: error in recvfrom() was not catched (thx Liviu Daia)

socklog 0.6.0
Sat, 12 Jan 2002 14:18:57 +0100
  * uncat: redirect prog's stdout to stderr; never writes to stdout
  * socklog-conf notify: redirects uncat's stdout to the pipe:
    'exec <> $PIPE', fixes wrong timeout handling seen in some
    configurations.
  * new: package/install-man for installing manpage links
  * doc: adapted
  * socklog.c,socklog-conf.c,uncat.c: code cleanup
  * doc: install.html: typos

socklog 0.5.4
Sun, 30 Dec 2001 19:18:29 +0100
  * uncat: new option -o: once, exit on eof
  * uncat: manpage adapted
  * doc: minor changes
  * socklog: trim 0-characters
  * Makefile: use ./support/compile, ./support/load

socklog 0.5.1
Tue, 20 Nov 2001 11:36:23 +0100
  * package socklog moved to smarden.org

socklog 0.5.0
Fri, 16 Nov 2001 15:53:07 +0100
  * minor beautification
  * deb: reorganized debian/rules

socklog 0.4.6
Sun, 11 Nov 2001 15:08:22 +0100
  * socklog: changed undocumented option -v to -V
  * Makefile: does not require gnu make (thx Jordan Krushen)
  * socklog-conf added
  * run socklog with softlimit
  * socklog-group mandatory, notify pipe mode 0620
  * doc: upgrade.html, socklog-conf.8.html, socklog-conf.8 added
  * doc: adapted

socklog 0.4.1
Fri, 12 Oct 2001 11:04:29 +0200
  * uncat: continue; on error_again, fixes wrong timeouts
  * uncat: more verbose on -v
  * deb: moved to unofficial, fhs failures
  * socklog-notify: use mailsubj
  * doc: improved configuration.html
  * doc: how to disable log event notifications

socklog 0.4.0
Fri, 21 Sep 2001 17:43:09 +0200
  * changed to new primary email address <pape@smarden.org>
  * BSD license
  * doc: minor changes

socklog 0.3.6
Mon, 17 Sep 2001 18:26:12 +0200
  * doc: updated

socklog 0.3.5
Sun, 16 Sep 2001 20:12:01 +0200
  * new: tryto, uncat
  * new: network logging concept
  * new: log event notification
  * deb: cleaner binary package (rm -rf (socklog/{compile,etc,doc,man})

socklog 0.3.0
Tue, 14 Aug 2001 12:26:02 +0200
  * installs into /package (see http://cr.yp.to/slashpackage.html)
  * no code changes

socklog 0.2.2
Fri, 22 Jun 2001 11:59:10 +0200  
  * LDFLAGS for solaris in Makefile
  * doc: benefits.html added, describing logfile rotation based on file size

socklog 0.2.1
Tue, 19 Jun 2001 11:48:28 +0200
  * support for solaris (thx Gary Gendel)
  * deb: provides: system-log-daemon (thx ska)

socklog 0.2.0
Mon, 11 Jun 2001 13:31:42 +0200
  * ucspi mode added.
  * use setgroups() before setgid() (thx ari)
  * buffering output (thx ari)
  * doc: Examples added (thx Eduardo Augusto Alvarenga, Paul Jarc)
  * compiles on openbsd 2.9 (thx clemensF)

socklog 0.1.2
Fri,  1 Jun 2001 10:50:36 +0200
  * doc: improved

socklog 0.1.1
Tue, 29 May 2001 13:26:24 +0200
  * deb: provides log directories for default log/run files
  * deb: add user 'log' in postinst
  * doc: improved

socklog 0.1.0
Mon, 28 May 2001 11:39:36 +0200
  * initial release
