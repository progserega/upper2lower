#!/bin/bash
tmp_root="`pwd`/debian_root_build"
VER=`cat VERSION`
# Architecture: amd64/i386/armel/all
ARCH="i386"

mkdir -p ${tmp_root}/usr/local/bin
strip upper2lower
install -o root -g root -m 755 upper2lower ${tmp_root}/usr/local/bin
install -o root -g root -m 755 create_dokuwiki_pages_from_dir  ${tmp_root}/usr/local/bin
install -o root -g root -m 755 rename2dokuwiki_media_format  ${tmp_root}/usr/local/bin
install -o root -g root -m 755 rename2dokuwiki_media_format_full_cur_dir  ${tmp_root}/usr/local/bin
install -o root -g root -m 755 rename_up2low ${tmp_root}/usr/local/bin
# build deb:
mkdir ${tmp_root}/DEBIAN
find ${tmp_root}/etc | sed "s/^/\//;s/.*debian_root_build\/etc/etc/g" > ${tmp_root}/DEBIAN/conffiles
echo "Package: upper2lower
Version: ${VER}
Architecture: ${ARCH}
Maintainer: progserega@gmail.com
Priority: optional
Description: Convert upper case to lower
" > ${tmp_root}/DEBIAN/control
dpkg -b ${tmp_root} upper2lower-${VER}.deb

