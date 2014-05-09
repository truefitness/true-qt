#!/usr/bin/make

DEBVERSION := 4.8.4+dfsg
UBVERSION := 0ubuntu18.3~ubuntu12.04.1
TRVERSION := +true4
VERSION := ${DEBVERSION}-${UBVERSION}${TRVERSION}
APPNAME=qt4-x11
SRCDIR=./src
DEBDIR=./debs
APPDIR=${SRCDIR}/${APPNAME}-${VERSION}
TARNAME=${APPDIR}.tar.gz
DSCNAME=${APPNAME}_${VERSION}.dsc
TARORIGNAME="${APPNAME}_${VERSION}.orig.tar.gz"
MAINTAINER=mpnolan@truefitness.com
BUILDDIR=${SRCDIR}/${APPNAME}-${DEBVERSION}
#DEBDIR := ${APPDIR}/debian
BUILD_DEPENDS =debhelper (>= 8.9.9)  dpkg-dev (>= 1.16.1), flex  freetds-dev, libasound2-dev  libaudio-dev, libcups2-dev  libdbus-1-dev, libfreetype6-dev  libgl-dev, libgl1-mesa-dev  libglib2.0-dev, libglu-dev  libglu1-mesa-dev, libgstreamer-plugins-base0.10-dev  libgstreamer0.10-dev, libgtk2.0-dev  libice-dev, libicu-dev  libjpeg-dev, libmng-dev  libmysqlclient-dev, libpam0g-dev  libpng12-dev, libpq-dev  libreadline-dev, libsm-dev  libsqlite3-dev, libssl-dev  libtiff4-dev, libx11-dev  libxcursor-dev, libxext-dev  libxft-dev, libxi-dev (>= 2  libxinerama-dev, libxmu-dev  libxrandr-dev, libxrender-dev  libxslt1-dev, libxt-dev  libxtst-dev, libxv-dev  pkg-kde-tools (>= 0.14.2), rsync  unixodbc-dev, zlib1g-dev
FW_MIN_VERSION=0.9.91

# Define the Control File
define CONTROLDATA
Source: $(APPNAME)
Section: unknown
Priority: extra
Maintainer: Michael Nolan <mpnolan@truefitness.com>
Build-Depends:debhelper (>= 8.9.9)  dpkg-dev (>= 1.16.1), flex  freetds-dev, libasound2-dev  libaudio-dev, libcups2-dev  libdbus-1-dev, libfreetype6-dev  libgl-dev, libgl1-mesa-dev  libglib2.0-dev, libglu-dev  libglu1-mesa-dev, libgstreamer-plugins-base0.10-dev  libgstreamer0.10-dev, libgtk2.0-dev  libice-dev, libicu-dev  libjpeg-dev, libmng-dev  libmysqlclient-dev, libpam0g-dev  libpng12-dev, libpq-dev  libreadline-dev, libsm-dev  libsqlite3-dev, libssl-dev  libtiff4-dev, libx11-dev  libxcursor-dev, libxext-dev  libxft-dev, libxi-dev (>= 2  libxinerama-dev, libxmu-dev  libxrandr-dev, libxrender-dev  libxslt1-dev, libxt-dev  libxtst-dev, libxv-dev  pkg-kde-tools (>= 0.14.2), rsync  unixodbc-dev, zlib1g-dev
Standards-Version: 3.9.2
Homepage: http://www.truefitness.com 

Package: $(APPNAME)
Architecture: i386
Depends: $${shlibs:Depends}, $${misc:Depends}
Recommends:  
Description: Custom Qt build for True Fitness
endef

export CONTROLDATA

#all: shownames tars dhmake build
all: shownames unpack build repo

shownames:
	@echo packaging ${APPDIR}
	@echo packagename=${APPNAME}
	@echo version=${VERSION}
	@echo dirname=${APPDIR}
	@echo debdir=${DEBDIR}
	@echo srcdir=${SRCDIR}
	@echo dscname=${DSCNAME}
	@echo buildir=${BUILDDIR}	
	
#tars:
	#@echo copying sourcetree
	#cp -a ../touch ${APPDIR}
	#@echo creating tar archive
	#tar czf ${TARNAME} ${APPDIR}
	#@echo creating .orig tar archive copy
	#cp ${TARNAME} ${TARORIGNAME}

	#echo extracting tar...
	#tar xzf ${TARNAME}

unpack:
	@echo dpkg-source ...
	(cd ${SRCDIR}; dpkg-source -x ${DSCNAME})


dhmake:
	@echo dh_make...
	(cd ${BUILDDIR}; dh_make -m -e ${MAINTAINER})
	(cd ${DEBDIR} ; rm *.ex *.EX )
	cp rules ${DEBDIR}/rules
	echo "$$CONTROLDATA" > ${DEBDIR}/control


source:
	@echo "creating source package..."
	debuild --no-lintian -S -uc -us -sd

build:
	@echo building...
	( cd ${BUILDDIR}; dpkg-buildpackage -rfakeroot -b -us -uc -j4)


movedebs:	
	@echo moving...
	@mkdir ${DEBDIR}
	( mv ${SRCDIR}/*.deb ${DEBDIR} ) 

repo:
	@ echo building repository
	@mkdir -p repo/pool/b 
	@mkdir -p repo/pool/p
	cp -a archive/* . 
	cp ${SRCDIR}/*.deb repo/pool/b
	(cd repo; dpkg-scanpackages . /dev/null | gzip -9c > Packages.gz)
	
repo-clean:
	rm -rf ${BUILDDIR}
	rm -rf repo 

clean:
	rm -rf ${SRCDIR}/*.deb 
	rm -rf ${BUILDDIR}
	rm -rf repo

		
