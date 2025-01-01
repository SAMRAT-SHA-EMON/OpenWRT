PKG_NAME:=my-filter
PKG_RELEASE:=1
PKG_VERSION:=1.0
PKG_MAINTAINER:=Saim Uddin Samrat Sha Emon <samratshaemon13@gmail.com>
PKG_LICENSE:=GPL-2.0
PKG_DEPENDS:=libubus libubox uloop iptables
PKG_SOURCE_URL:=https://github.com/SAMRAT-SHA-EMON/openwrt-my-filter.git;branch=master 
PKG_SOURCE_DIR:= $(BUILD_DIR)/my-filter
PKG_SOURCE_SUBDIR:=src
PKG_SOURCE_DATE_OPT:=1
PKG_SOURCE_PROTO:=git
PKG_SOURCE_DIR_STRIP:=1
PKG_SOURCE_FILES:=src/CMakeLists.txt src/my_filter.cpp 

include $(TOPDIR)/feeds/packages/Makefile.include
