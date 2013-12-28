Name:      Tuningdrake
Summary:   Tuning your Mandriva  
Version:   0.2.0  
Release: 2bdk.2010.0
License: GPL v3
Group: File tools
BuildRoot: %{_tmppath}/%{name}-%{version}-buildroot
Source: Tuningdrake-%{version}.tar.gz
Packager: kapyderi
Distribution: Mandriva
Url: www.kapyderi.blogspot.com
Vendor: kapyderi

%description
TuningDrake es un script que pretende facilitar tener su Mandriva
con todo lo necesario para navegar, ver videos, etc.  
TuningDrake is an bash script which goal is make most easy have your
Mandriva system with all the needed for surf the web, play video, etc.
For more info visit http://blogdrake.net/node/15932 (in Spanish)

%prep
%setup -c %{$RPM_BUILD_DIR}

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/{usr/{bin,sbin,share/applications,share/icons},etc/pam.d}
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/Tuningdrake-%{version} $RPM_BUILD_ROOT/usr/sbin/Tuningdrake
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/Tuningdrake-%{version}-qt $RPM_BUILD_ROOT/usr/sbin/Tuningdrake-qt
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/Tuningdrake-%{version}-cli $RPM_BUILD_ROOT/usr/sbin/Tuningdrake-cli
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/Tuningdrake-backend-%{version} $RPM_BUILD_ROOT/usr/sbin/Tuningdrake-backend
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/Tuningdrake.desktop $RPM_BUILD_ROOT/usr/share/applications/Tuningdrake.desktop
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/Tuningdrake-qt.desktop $RPM_BUILD_ROOT/usr/share/applications/Tuningdrake-qt.desktop
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/tuningdrake.png $RPM_BUILD_ROOT/usr/share/icons/tuningdrake.png
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/Tuningdrake-pam $RPM_BUILD_ROOT/etc/pam.d/Tuningdrake
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/Tuningdrake-pam $RPM_BUILD_ROOT/etc/pam.d/Tuningdrake-qt
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/Tuningdrake-pam-cli $RPM_BUILD_ROOT/etc/pam.d/Tuningdrake-cli
ln -sf consolehelper $RPM_BUILD_ROOT/usr/bin/Tuningdrake
ln -sf consolehelper $RPM_BUILD_ROOT/usr/bin/Tuningdrake-qt
ln -sf consolehelper $RPM_BUILD_ROOT/usr/bin/Tuningdrake-cli

%clean  
rm -rf $RPM_BUILD_ROOT $RPM_BUILD_DIR/

%post
%{update_menus}

%postun
%{clean_menus}

%files  
/usr/sbin/Tuningdrake  
/usr/sbin/Tuningdrake-qt
/usr/sbin/Tuningdrake-cli  
/usr/sbin/Tuningdrake-backend
/usr/bin/Tuningdrake
/usr/bin/Tuningdrake-cli
/usr/bin/Tuningdrake-qt
/usr/share/applications/Tuningdrake-qt.desktop
/usr/share/applications/Tuningdrake.desktop
%config(noreplace) /etc/pam.d/Tuningdrake
%config(noreplace) /etc/pam.d/Tuningdrake-qt
%config(noreplace) /etc/pam.d/Tuningdrake-cli
/usr/share/icons/tuningdrake.png

%changelog
* Fri Nov 13 2009 <kapydei@eresmas.com> %{version}-%{release}
- Añadidos nuevos gui
- Nuevas mejoras

* Fri Nov 13 2009 <kapydei@eresmas.com> %{version}-%{release}
- Update to 0.2.0
- Fix issue with mib
- Add new options

* Fri Oct 30 2009 <j.alberto.vc@gmail.com> %{version}-%{release}
- Update to 0.1.6
- Fix issue with plf
- Add new options

* Tue Oct 27 2009 <j.alberto.vc@gmail.com>
- Fix little error in Tuningdrake-backend

* Thu Oct 22 2009 <j.alberto.vc@gmail.com>
- Fix little errors in scripts

* Fri Oct 16 2009 <j.alberto.vc@gmail.com>
- Update to 0.1.5 Version
- Fix some errors of 0.1.4 version
- Created Tuningdrake-backend to handle common code

* Wed Oct 14 2009 <j.alberto.vc@gmail.com>
- Update to 0.1.4 Version
- Fix some errors of 0.1.3 version
- Add Chose of MUD repositories

* Thu Jun 04 2009 <j.alberto.vc@gmail.com> 
- Change mdv sufix by bdk

* Wed May 27 2009 <j.alberto.vc@gmail.com> 
- Fix errors of the previous rpm
- Fix mistake in the previous changelog
* Mon May 25 2009 <j.alberto.vc@gmail.com>
- Modified from the spec created by the blogdrake's user will
- Join in one rpm all the Tuningdrake variants
