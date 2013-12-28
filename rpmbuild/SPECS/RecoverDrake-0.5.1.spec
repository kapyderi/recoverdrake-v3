Name:      RecoverDrake
Summary:   Tuneando los rpm's de tu Mandriva  
Version:   0.5.1  
Release: 3bdk.2010.1
License: GPL v2
Group: File tools
BuildRoot: %{_tmppath}/%{name}-%{version}-buildroot
Source0: RecoverDrake-%{version}.tar.gz
Packager: kapyderi
Distribution: Mandriva
Url: www.kapyderi.blogspot.com
Vendor: kapyderi
BuildArch: noarch
Requires: zenity, sudo, bash, kwrite, libstdc++5, ndiswrapper

%description
RecoverDrake es un script que pretende facilitar la instalacion de paquetes trás una nueva instalación sin
tener que morir en el intento. Para tenerlo todo como estaba en su estado original.
Tambien sirve para "maquear" algunas partes de Mandriva y solución a problemas "conocidos"
Dedicado a mi mujer y a mis dos hijas Atenea y Minerva.

%prep
%setup -c %{$RPM_BUILD_DIR}

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/{usr/{bin,sbin,share/applications,share/icons},etc/pam.d,root}
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/%{name}-%{version} $RPM_BUILD_ROOT/usr/sbin/RecoverDrake
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/%{name}.desktop $RPM_BUILD_ROOT/usr/share/applications/RecoverDrake.desktop
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/%{name}.png $RPM_BUILD_ROOT/usr/share/icons/RecoverDrake.png
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/%{name}-pam $RPM_BUILD_ROOT/etc/pam.d/RecoverDrake
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/datos_wifi $RPM_BUILD_ROOT/usr/sbin/datos_wifi
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/datos_wifi_open $RPM_BUILD_ROOT/usr/sbin/datos_wifi_open
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/matador $RPM_BUILD_ROOT/usr/sbin/matador
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/wifidrake.log $RPM_BUILD_ROOT/root/wifidrake.log
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/acercade.txt $RPM_BUILD_ROOT/root/acercade.txt
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/sp-sc-auth.tar.gz $RPM_BUILD_ROOT/root/sp-sc-auth.tar.gz
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/qsopcast.tar.gz $RPM_BUILD_ROOT/root/qsopcast.tar.gz
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/kttsd.tar.gz $RPM_BUILD_ROOT/root/kttsd.tar.gz
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
/usr/share/icons/RecoverDrake.png
/usr/sbin/datos_wifi
/usr/sbin/datos_wifi_open
/usr/sbin/matador
/root/wifidrake.log
/root/acercade.txt
/root/sp-sc-auth.tar.gz
%config(noreplace) /etc/pam.d/RecoverDrake
/root/qsopcast.tar.gz
/root/kttsd.tar.gz

%changelog
* Sat Oct 23 2010 <kapyderi@eresmas.com> %{version}-%{release}
- Bugs corregidos

* Wed Oct 13 2010 <kapyderi@eresmas.com> 0.5.0.3bdk
- Elección de ruta para copiar los rpm's y tambien para el volcado
- Generación de fichero de cambios realizados durante el volcado
- Instalación de dependencias
- Instalación de versiones inestables o no soportados de kde y restauracion
- Instalación de cualquier escritorio (necesario por si falla un escritorio)
- Guardar configuraciones de sistema y restauracion
- Copia de seguridad y restauracion 
- Instalar drivers wifi con ndiswrapper
- Solución a problemas conocidos: Desconexion Wifi WEB/WPA
- Solución a problemas conocidos: Desconexion Wifi Abierta
- Solución a problemas conocidos: Codecs audio/video
- Solución a problemas conocidos: Exceso de memoria en procesos con Dolphin
- Solución a problemas conocidos: Configurar sopcast/qsopcast
- Solución a problemas conocidos: Firefox con pdf
- Solución a problemas conocidos: kdeinit4 inicia con error
- Solución a problemas conocidos: Recuperar configuración de kde
- Solución a problemas conocidos: VirtualBox no se ejecuta
- Solución a problemas conocidos: RPM database bloqued
- Solución a problemas conocidos: Excluir actualización de paquete
- Solución a problemas conocidos: KTTSD no se esta ejecutando
- Solución a problemas conocidos: NTFS sin permisos
- Solución a problemas conocidos: Preparar para autocompilar (DKMS)
- Modificación automatica del fichero .lst con la versión de Mandriva que se este utilizando Free, One, Flash o Powerpack
- Bugs corregidos

* Sat Jun 12 2010 <kapyderi@eresmas.com> 0.3.0-2bdk
- Modo interactivo.
- Edición de repositorios.

* Fri Apr 23 2010 <kapyderi@eresmas.com> 0.2.0-2bdk
- Introducción de repositorios de forma manual.
- Bugs corregidos.
- Comentarios en consola para todas las opciones.
- Volcado totalmente automatico.

* Sun Apr 4 2010 <kapyderi@eresmas.com> 0.1.3-2bdk
- Introducción de nombre de usuario para evitar conflictos.

* Sun Apr 4 2010 <kapyderi@eresmas.com> 0.1.2-2bdk
- Correccion de usuarios con nombre muy largo.

* Sat Apr 3 2010 <kapyderi@eresmas.com> 0.1.1-2bdk
- Reducción ventana de bienvenida.
- Instalación de dependencias.

* Mon Mar 22 2010 <kapyderi@eresmas.com> 0.1.0-2bdk
- Se puede ejecutar abriendo una consola para ver los resultados

* Sat Feb 27 2010 <kapyderi@eresmas.com> 0.1.1-1bdk
- Bugs corregidos
- Opción de auto-orphans
- Opción de confirmación de actualizar repositorios

* Sat Feb 19 2010 <kapyderi@eresmas.com> 0.1.0-1bdk
- Comienzo del Script
