Name:      RecoverDrake
Summary:   Tuneando los rpm's de tu Mandriva  
Version:   0.1.0  
Release: 2bdk
License: GPL v2
Group: File tools
BuildRoot: %{_tmppath}/%{name}-%{version}-buildroot
Source: RecoverDrake-%{version}.tar.gz
Packager: kapyderi
Distribution: Mandriva
Url: www.kapyderi.blogspot.com
Vendor: kapyderi
BuildArch: noarch


%description
RecoverDrake es un script que pretende facilitar la instalacion de paquetes trás una nueva instalación sin
tener que morir en el intento, para tenerlo todo como estaba en su estado original.

%prep
%setup -c %{$RPM_BUILD_DIR}

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/{usr/{bin,sbin,share/applications,share/icons},etc/pam.d}
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/%{name}-%{version} $RPM_BUILD_ROOT/usr/sbin/RecoverDrake
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/%{name}.desktop $RPM_BUILD_ROOT/usr/share/applications/RecoverDrake.desktop
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/%{name}.png $RPM_BUILD_ROOT/usr/share/icons/RecoverDrake.png
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/%{name}-pam $RPM_BUILD_ROOT/etc/pam.d/RecoverDrake
ln -sf consolehelper $RPM_BUILD_ROOT/usr/bin/RecoverDrake

%clean  
rm -rf $RPM_BUILD_ROOT $RPM_BUILD_DIR/

%post
%{update_menus}

%postun
%{clean_menus}

%files  
/usr/sbin/RecoverDrake  
/usr/bin/RecoverDrake
/usr/share/applications/RecoverDrake.desktop
%config(noreplace) /etc/pam.d/RecoverDrake
/usr/share/icons/RecoverDrake.png


%changelog

* Mon Mar 22 2010 <kapyderi@eresmas.com> %{version}-%{release}
- Se puede ejecutar abriendo una consola para ver los resultados

* Sat Feb 27 2010 <kapyderi@eresmas.com> %{version}-%{release}
- Bugs corregidos
- Opción de auto-orphans
- Opción de confirmación de actualizar repositorios

* Sat Feb 19 2010 <kapyderi@eresmas.com> %{version}-%{release}
- Comienzo del Script
