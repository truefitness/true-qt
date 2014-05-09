#!/usr/bin/make

#VERSION := $(shell git describe --long | sed s/-/./g)
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
BUILD_DEPENDS =debhelper , cdbs, quilt, autotools-dev, flex, bison, gstreamer-tools, libasound2-dev, libdbus-glib-1-dev, libglib2.0-dev, libgstreamer0.10-dev, libgstreamer-plugins-base0.10-dev, libnl-3-dev, libsndfile1-dev, libusb-dev, libcap-ng-dev, libudev-dev, libreadline-dev, check , python3-dev 
FW_MIN_VERSION=0.9.91

# Define the Control File
define CONTROLDATA
Source: $(APPNAME)
Section: unknown
Priority: extra
Maintainer: Michael Nolan <mpnolan@truefitness.com>
Build-Depends:debhelper (>= 8.1.3), cdbs (>= 0.4.97), quilt, autotools-dev, flex, bison, gstreamer-tools, libasound2-dev (>= 1.0.24.1), libdbus-glib-1-dev, libglib2.0-dev (>= 2.28), libgstreamer0.10-dev (>= 0.10.30), libgstreamer-plugins-base0.10-dev (>= 0.10.30), libnl-3-dev, libsndfile1-dev, libusb-dev, libcap-ng-dev, libudev-dev, libreadline-dev, check (>= 0.9.8-1.1), python3-dev
Standards-Version: 3.9.2
Homepage: http://www.truefitness.com 

Package: $(APPNAME)
Architecture: i386
Depends: $${shlibs:Depends}, $${misc:Depends}
Recommends:  
Description: Linux Bluetooth Stack.
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
	
tars:
	@echo copying sourcetree
	cp -a ../touch ${APPDIR}
	@echo creating tar archive
	tar czf ${TARNAME} ${APPDIR}
	@echo creating .orig tar archive copy
	cp ${TARNAME} ${TARORIGNAME}

	echo extracting tar...
	tar xzf ${TARNAME}

# Placeholder, copy source to this repos
#get_source:
#	wget http://qa-ec2.netpulse.ws:80/pantheon/updates/oem/true/source/bluexxx


unpack:
	@echo dpkg-source ...
	(cd ${SRCDIR}; dpkg-source -x ${DSCNAME})


dhmake:
	@echo dh_make...
	(cd ${APPDIR}; dh_make -s -e ${MAINTAINER})
	(cd ${DEBDIR} ; rm *.ex *.EX )
	cp rules ${DEBDIR}/rules
	echo "$$CONTROLDATA" > ${DEBDIR}/control


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

		
