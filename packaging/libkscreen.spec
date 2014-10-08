# 
# Do NOT Edit the Auto-generated Part!
# Generated by: spectacle version 0.27
# 

Name:       libkscreen

# >> macros
# << macros

Summary:    API to control screen settings
Version:    5.0.95
Release:    1
Group:      System/Base
License:    LGPLv2.1+
URL:        http://www.kde.org
Source0:    %{name}-%{version}.tar.xz
Source100:  libkscreen.yaml
Source101:  libkscreen-rpmlintrc
Requires:   kf5-filesystem
Requires(post): /sbin/ldconfig
Requires(postun): /sbin/ldconfig
BuildRequires:  pkgconfig(Qt5Core)
BuildRequires:  pkgconfig(Qt5DBus)
BuildRequires:  pkgconfig(Qt5Xml)
BuildRequires:  pkgconfig(Qt5Network)
BuildRequires:  pkgconfig(Qt5Gui)
BuildRequires:  pkgconfig(Qt5Widgets)
BuildRequires:  pkgconfig(Qt5Concurrent)
BuildRequires:  pkgconfig(Qt5Test)
BuildRequires:  pkgconfig(Qt5X11Extras)
BuildRequires:  pkgconfig(x11-xcb)
BuildRequires:  pkgconfig(xrandr)
BuildRequires:  kf5-rpm-macros
BuildRequires:  extra-cmake-modules

%description
API to control screen settings.


%package devel
Summary:    Development files for %{name}
Group:      Development/Libraries
Requires:   %{name} = %{version}-%{release}

%description devel
The %{name}-devel package contains the files necessary to develop applications
that use %{name}.


%prep
%setup -q -n %{name}-%{version}

# >> setup
# << setup

%build
# >> build pre
%kf5_make
# << build pre



# >> build post
# << build post

%install
rm -rf %{buildroot}
# >> install pre
%kf5_make_install
# << install pre

# >> install post
# << install post

%files
%defattr(-,root,root,-)
%doc COPYING COPYING.LIB
%{_kf5_libdir}/libKF5Screen.so.*
%{_kf5_plugindir}/*
# >> files
# << files

%files devel
%defattr(-,root,root,-)
%{_kf5_libdir}/libKF5Screen.so
%{_kf5_libdir}/cmake/KF5Screen
%{_kf5_includedir}/KScreen
%{_kf5_includedir}/kscreen_version.h
%{_kf5_mkspecsdir}/qt_KScreen.pri
%{_kf5_libdir}/pkgconfig/kscreen2.pc
# >> files devel
# << files devel
