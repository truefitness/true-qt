Format: 3.0 (quilt)
Source: qt4-x11
Binary: libqtcore4, libqt4-core, libqtgui4, libqt4-gui, libqt4-network, libqt4-opengl, libqt4-script, libqt4-scripttools, libqt4-sql, libqt4-sql-mysql, libqt4-sql-odbc, libqt4-sql-psql, libqt4-sql-sqlite, libqt4-sql-tds, libqt4-svg, libqt4-webkit, libqt4-xml, libqt4-xmlpatterns, libqt4-dbus, libqt4-qt3support, libqt4-designer, libqt4-help, libqt4-assistant, libqt4-test, libqt4-declarative, libqt4-declarative-folderlistmodel, libqt4-declarative-gestures, libqt4-declarative-particles, libqt4-declarative-shaders, libqt4-dev, libqt4-dev-bin, libqt4-private-dev, libqt4-opengl-dev, libqt4-dbg, libqt4-designer-dbg, libqt4-qt3support-dbg, libqt4-script-dbg, libqt4-webkit-dbg, libqt4-xmlpatterns-dbg, qt4-bin-dbg, qt4-demos-dbg, qt4-designer, qt4-dev-tools, qt4-qmake, qt4-qtconfig, qt4-demos, qt4-qmlviewer, qt4-linguist-tools, qdbus, qt4-doc, qt4-doc-html, qt4-default
Architecture: any all
Version: 4:4.8.4+dfsg-0ubuntu18.3~ubuntu12.04.1+true4
Maintainer: Kubuntu Developers <kubuntu-devel@lists.ubuntu.com>
Uploaders: Fathi Boudra <fabo@debian.org>, Modestas Vainius <modax@debian.org>, Sune Vuorela <debian@pusling.com>, Pino Toscano <pino@debian.org>, Lisandro Damián Nicanor Pérez Meyer <lisandro@debian.org>, Timo Jyrinki <timo@debian.org>
Homepage: http://qt-project.org/
Standards-Version: 3.9.3
Vcs-Browser: http://bazaar.launchpad.net/~kubuntu-packagers/kubuntu-packaging/qt
Vcs-Bzr: https://code.launchpad.net/~kubuntu-packagers/kubuntu-packaging/qt
Build-Depends: debhelper (>= 9), dpkg-dev (>= 1.16.1), flex, freetds-dev, g++ (>= 4:4.5) [s390], libasound2-dev [linux-any], libaudio-dev, libcups2-dev, libdbus-1-dev, libfreetype6-dev, libgl1-mesa-dev [!armel !armhf] | libgl-dev [!armel !armhf], libgles2-mesa-dev [armel armhf] | libgles2-dev [armel armhf], libglib2.0-dev, libglu1-mesa-dev [!armel !armhf] | libglu-dev [!armel !armhf], libgstreamer-plugins-base0.10-dev, libgstreamer0.10-dev, libgtk2.0-dev, libice-dev, libicu-dev, libjpeg-dev, libmng-dev, libmysqlclient-dev, libpam0g-dev, libpng-dev, libpq-dev, libreadline-dev, libsm-dev, libsqlite3-dev, libssl-dev, libtiff-dev, libx11-dev, libxcursor-dev, libxext-dev, libxft-dev, libxi-dev, libxinerama-dev, libxmu-dev, libxrandr-dev, libxrender-dev, libxslt1-dev, libxt-dev, libxtst-dev, libxv-dev, pkg-kde-tools (>= 0.14.2), rsync, unixodbc-dev, zlib1g-dev
Package-List: 
 libqt4-assistant deb oldlibs extra
 libqt4-core deb oldlibs extra
 libqt4-dbg deb debug extra
 libqt4-dbus deb libs optional
 libqt4-declarative deb libs optional
 libqt4-declarative-folderlistmodel deb libs optional
 libqt4-declarative-gestures deb libs optional
 libqt4-declarative-particles deb libs optional
 libqt4-declarative-shaders deb libs optional
 libqt4-designer deb libs optional
 libqt4-designer-dbg deb debug extra
 libqt4-dev deb libdevel optional
 libqt4-dev-bin deb devel optional
 libqt4-gui deb oldlibs extra
 libqt4-help deb libs optional
 libqt4-network deb libs optional
 libqt4-opengl deb libs optional
 libqt4-opengl-dev deb libdevel optional
 libqt4-private-dev deb libdevel optional
 libqt4-qt3support deb libs optional
 libqt4-qt3support-dbg deb debug extra
 libqt4-script deb libs optional
 libqt4-script-dbg deb debug extra
 libqt4-scripttools deb libs optional
 libqt4-sql deb libs optional
 libqt4-sql-mysql deb libs optional
 libqt4-sql-odbc deb libs optional
 libqt4-sql-psql deb libs optional
 libqt4-sql-sqlite deb libs optional
 libqt4-sql-tds deb libs optional
 libqt4-svg deb libs optional
 libqt4-test deb libs optional
 libqt4-webkit deb oldlibs extra
 libqt4-webkit-dbg deb oldlibs extra
 libqt4-xml deb libs optional
 libqt4-xmlpatterns deb libs optional
 libqt4-xmlpatterns-dbg deb debug extra
 libqtcore4 deb libs optional
 libqtgui4 deb libs optional
 qdbus deb utils optional
 qt4-bin-dbg deb debug extra
 qt4-default deb libs optional
 qt4-demos deb x11 optional
 qt4-demos-dbg deb debug extra
 qt4-designer deb devel optional
 qt4-dev-tools deb devel optional
 qt4-doc deb doc optional
 qt4-doc-html deb doc optional
 qt4-linguist-tools deb devel optional
 qt4-qmake deb devel optional
 qt4-qmlviewer deb devel optional
 qt4-qtconfig deb x11 optional
Checksums-Sha1: 
 58e8f285501cb84ed33e512573a99357b889fbda 199762900 qt4-x11_4.8.4+dfsg.orig.tar.xz
 57939d1c0674792f53ab09f365b69790ae200a89 513941 qt4-x11_4.8.4+dfsg-0ubuntu18.3~ubuntu12.04.1+true4.debian.tar.gz
Checksums-Sha256: 
 47a735635c11205911501a7436e6140235911012282a16b738b3cc1442e1b4f6 199762900 qt4-x11_4.8.4+dfsg.orig.tar.xz
 73fc6dde77fb48b069ab4039edba69470878c4b17c9a7d0f662fed3ab83c0eeb 513941 qt4-x11_4.8.4+dfsg-0ubuntu18.3~ubuntu12.04.1+true4.debian.tar.gz
Files: 
 d74665f5ae3e0b9e4cc407375f872008 199762900 qt4-x11_4.8.4+dfsg.orig.tar.xz
 ac8a89aa5762ef533c7088f8a2cd4343 513941 qt4-x11_4.8.4+dfsg-0ubuntu18.3~ubuntu12.04.1+true4.debian.tar.gz
Original-Maintainer: Debian Qt/KDE Maintainers <debian-qt-kde@lists.debian.org>
