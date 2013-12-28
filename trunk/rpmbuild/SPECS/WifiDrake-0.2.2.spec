Name:      WifiDrake
Summary:   Controlador de caidas de señal de wifi para encriptaciones tipo WEB  
Version:   0.2.2  
Release: 1bdk.2010.1
License: GPL v2
Group: File tools
BuildRoot: %{_tmppath}/%{name}-%{version}-buildroot
Source: WifiDrake-%{version}.tar.gz
Packager: kapyderi
Distribution: Mandriva
Url: www.kapyderi.blogspot.com
Vendor: kapyderi
BuildArch: noarch
Requires: zenity, sudo


%description
WifiDrake es un script que realiza el mantenimiento de la wifi, tras caidas del linea. (Esta versión solo es valida para encriptaciones tipo WEB)

%prep
%setup -c %{$RPM_BUILD_DIR}

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/{usr/{bin,sbin,share/applications,share/icons},etc/pam.d,root}
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/%{name}-%{version} $RPM_BUILD_ROOT/usr/sbin/WifiDrake
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/datos_wifi $RPM_BUILD_ROOT/usr/sbin/datos_wifi
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/wifidrake.log $RPM_BUILD_ROOT/root/wifidrake.log
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/%{name}.desktop $RPM_BUILD_ROOT/usr/share/applications/WifiDrake.desktop
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/%{name}.png $RPM_BUILD_ROOT/usr/share/icons/WifiDrake.png
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/%{name}-pam $RPM_BUILD_ROOT/etc/pam.d/WifiDrake
ln -sf consolehelper $RPM_BUILD_ROOT/usr/bin/WifiDrake

%clean  
rm -rf $RPM_BUILD_ROOT $RPM_BUILD_DIR/

%post
%{update_menus}

%postun
%{clean_menus}

%files  
/usr/sbin/WifiDrake  
/usr/bin/WifiDrake
/usr/sbin/datos_wifi
/root/wifidrake.log
/usr/share/applications/WifiDrake.desktop
%config(noreplace) /etc/pam.d/WifiDrake
/usr/share/icons/WifiDrake.png


%changelog

* Sat Jul 24 2010 <kapyderi@eresmas.com> %{version}-%{release}
- Instalación de dependencias

* Sat May 22 2010 <kapyderi@eresmas.com> 0.2.1-1.bdk}
- Arreglo de Bugs en crontab
- Generación de crontab totalmente automatica

* Sat Apr 3 2010 <kapyderi@eresmas.com> 0.2.0-1.bdk
- Comienzo del Script
