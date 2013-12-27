Name: RecoverDrake
Summary: Mandriva and Mageia's rpm tuning 
Summary(es): Tuneando los rpm's de tu Mandriva y Mageia... de momento!!
Version: 2.62.61 
Release: 1bdk
License: GPL v2	
Group: File tools
BuildRoot: %{_tmppath}/buildroot-%{name}-%{version}
Source: RecoverDrake-%{version}.tar.gz
Packager: kapyderi
Distribution: Mandriva/Mageia
Url: www.kapyderi.blogspot.com
Vendor: kapyderi
BuildArch: i586
Requires: libkdesu5, qt4-database-plugin-sqlite

%description
RecoverDrake is an 'easy way' installation program for new installations.
This script allows you to keep all as you have before.
We add a lot of configuration utilities.
RecoverDrake is also used to fix some Mandriva/Mageia sections and solve known bugs.
Dedicated to my wife, Paky and my daughters, Athena and Minerva.

%description -l es
RecoverDrake es un programa que pretende facilitar la instalacion de
paquetes tras una nueva instalación sin
tener que morir en el intento. Para tenerlo todo como estaba en su
estado original.
Se le han añadido muchisimas nuevas opciones de configuración y utilidades.
Tambien sirve para "maquear" algunas partes de Mandriva/Mageia y solución a
problemas "conocidos"
Dedicado a mi mujer, Paky y a mis dos hijas, Atenea y Minerva.

%prep
%setup -c %{$RPM_BUILD_DIR}

%install
rm -rf $RPM_BUILD_ROOT
if [ ! -e $RPM_BUILD_ROOT/usr/share/RecoverDrake ];
then
    mkdir -p $RPM_BUILD_ROOT/usr/share/RecoverDrake
fi
mkdir -p $RPM_BUILD_ROOT/{usr/{bin,sbin,share/applications,share/icons,share/RecoverDrake},etc/pam.d,root}
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/%{name} $RPM_BUILD_ROOT/usr/sbin/RecoverDrake
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverOrphans $RPM_BUILD_ROOT/usr/sbin/RecoverOrphans
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverResOrphans $RPM_BUILD_ROOT/usr/sbin/RecoverResOrphans
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverRpm $RPM_BUILD_ROOT/usr/sbin/RecoverRpm
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverResRpm $RPM_BUILD_ROOT/usr/sbin/RecoverResRpm
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverBackup $RPM_BUILD_ROOT/usr/sbin/RecoverBackup
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverConf $RPM_BUILD_ROOT/usr/sbin/RecoverConf
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverConvert $RPM_BUILD_ROOT/usr/sbin/RecoverConvert
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverMove $RPM_BUILD_ROOT/usr/sbin/RecoverMove
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverMovemp3 $RPM_BUILD_ROOT/usr/sbin/RecoverMovemp3
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverMovewma $RPM_BUILD_ROOT/usr/sbin/RecoverMovewma
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverMoveac3 $RPM_BUILD_ROOT/usr/sbin/RecoverMoveac3
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverDolphin $RPM_BUILD_ROOT/usr/sbin/RecoverDolphin
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverPswd $RPM_BUILD_ROOT/usr/sbin/RecoverPswd
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverKTTSD $RPM_BUILD_ROOT/usr/sbin/RecoverKTTSD
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverExclu $RPM_BUILD_ROOT/usr/sbin/RecoverExclu
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverInclu $RPM_BUILD_ROOT/usr/sbin/RecoverInclu
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverRest $RPM_BUILD_ROOT/usr/sbin/RecoverRest
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverNTFS $RPM_BUILD_ROOT/usr/sbin/RecoverNTFS
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverSudo $RPM_BUILD_ROOT/usr/sbin/RecoverSudo
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverRename $RPM_BUILD_ROOT/usr/sbin/RecoverRename
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverSkype $RPM_BUILD_ROOT/usr/sbin/RecoverSkype
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverDVD $RPM_BUILD_ROOT/usr/sbin/RecoverDVD
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverSop $RPM_BUILD_ROOT/usr/sbin/RecoverSop
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverAntivirus $RPM_BUILD_ROOT/usr/sbin/RecoverAntivirus
#install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/Miscelanea.RecoverDrake.db.sqlite $RPM_BUILD_ROOT/usr/share/RecoverDrake/Miscelanea.RecoverDrake.db.sqlite
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/logo.png $RPM_BUILD_ROOT/usr/share/RecoverDrake/logo.png
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/RecoverDrake_en.qm $RPM_BUILD_ROOT/usr/share/RecoverDrake/RecoverDrake_en.qm
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/%{name}.desktop $RPM_BUILD_ROOT/usr/share/applications/RecoverDrake.desktop
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/%{name}.png $RPM_BUILD_ROOT/usr/share/icons/RecoverDrake.png
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/%{name}-pam $RPM_BUILD_ROOT/etc/pam.d/RecoverDrake
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/datos_wifi $RPM_BUILD_ROOT/usr/sbin/datos_wifi
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/datos_wifi_open $RPM_BUILD_ROOT/usr/sbin/datos_wifi_open
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/matador $RPM_BUILD_ROOT/usr/sbin/matador
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/wifidrake.log $RPM_BUILD_ROOT/root/wifidrake.log
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/sp-sc-auth.tar.gz $RPM_BUILD_ROOT/root/sp-sc-auth.tar.gz
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/libstdc++.tar.gz $RPM_BUILD_ROOT/root/libstdc++.tar.gz
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/qsopcast.tar.gz $RPM_BUILD_ROOT/root/qsopcast.tar.gz
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/kttsd.tar.gz $RPM_BUILD_ROOT/root/kttsd.tar.gz
install -m0644 $RPM_BUILD_DIR/%{name}-%{version}/wifi-firmware.tar.gz $RPM_BUILD_ROOT/root/wifi-firmware.tar.gz
install -m0755 $RPM_BUILD_DIR/%{name}-%{version}/Miscelanea.RecoverDrake.db.sqlite $RPM_BUILD_ROOT/root/Miscelanea.RecoverDrake.db.sqlite
#ln -sf consolehelper $RPM_BUILD_ROOT/usr/bin/RecoverDrake

%clean  
rm -rf $RPM_BUILD_ROOT $RPM_BUILD_DIR/

%post
%{update_menus}

%postun
%{clean_menus}

%files  
/usr/sbin/RecoverDrake
/usr/sbin/RecoverOrphans
/usr/sbin/RecoverResOrphans
/usr/sbin/RecoverRpm
/usr/sbin/RecoverResRpm 
/usr/sbin/RecoverBackup
/usr/sbin/RecoverConf
/usr/sbin/RecoverConvert
/usr/sbin/RecoverMove
/usr/sbin/RecoverMovewma
/usr/sbin/RecoverMoveac3
/usr/sbin/RecoverMovemp3
/usr/sbin/RecoverDolphin
/usr/sbin/RecoverPswd
/usr/sbin/RecoverKTTSD
/usr/sbin/RecoverExclu
/usr/sbin/RecoverInclu
/usr/sbin/RecoverRest
/usr/sbin/RecoverSkype
/usr/sbin/RecoverDVD
/usr/sbin/RecoverNTFS
/usr/sbin/RecoverSudo
/usr/sbin/RecoverRename
#/usr/bin/RecoverDrake
/usr/sbin/RecoverSop
/usr/sbin/RecoverAntivirus
#/usr/share/RecoverDrake/Miscelanea.RecoverDrake.db.sqlite
/usr/share/RecoverDrake/RecoverDrake_en.qm
/usr/share/RecoverDrake/logo.png
/root/Miscelanea.RecoverDrake.db.sqlite
/usr/share/applications/RecoverDrake.desktop
/usr/share/icons/RecoverDrake.png
/usr/sbin/datos_wifi
/usr/sbin/datos_wifi_open
/usr/sbin/matador
/root/wifidrake.log
/root/sp-sc-auth.tar.gz
%config(noreplace) /etc/pam.d/RecoverDrake
/root/qsopcast.tar.gz
/root/kttsd.tar.gz
/root/wifi-firmware.tar.gz
/root/libstdc++.tar.gz

%changelog
// falta añadir esta parte//

* Sat Jun 28 2012 <kapyder@eresmas.com>%{version}-%{release}
- Se mantiene la base de datos anterior o se crea si no existe.
- Bugs corregidos.

* Fri Jun 27 2012 <kapyder@eresmas.com> 2.31.28.bdk
- Canal IRC incluido.

* Wed Jun 25 2012 <kapyder@eresmas.com> 2.30.28.bdk
- Bugs corregidos.
- Google Translate incluido en browser.
- Centro de Control de Mandriva/Mageia incluido.

* Tue Jun 10 2012 <kapyder@eresmas.com> 2.24.20.bdk
- Bugs corregidos.
- Cambio automatico en idioma al seleccionar.

* Mon Jun 9 2012 <kapyder@eresmas.com> 2.22.18.bdk
- Bugs corregidos.
- Menu de administrador (no para usuarios normales).

* Sat Jun 8 2012 <kapyder@eresmas.com> 2.21.18.bdk
- Bugs corregidos.
- Reproductor de Video.
- Reproductor de Audio.
- Televisión por Internet.
- Radio por Internet.
- Funciones principales Interactivas.
y mucho mas...xD

* Sat Sep 24 2011 <kapyder@eresmas.com> 2.0.0
- Bugs corregidos.
- Programación mixta de Qt, C++, Script/Bash, zennity.
- Creacion de usuarios de mantenimiento de RecoverDrake.
- Acceso con claves (Por defecto admin/admin, para la primera entrada, luego se deshabilita.)
- Comprobación de dependencias necesarias.
- Recuperar paquetes huerfanos eliminados.
- Crear usb-live.
- Eliminar imagen iso.
- Añadir kde inestable.
- Actualizar kde inestable.
- Eliminar kde inestable.
- Instalar paquetes.
- Instalar todos los escritorios, individual o masivo.
- Instalar cups de impresoras.
- Instalar wifi con ndiswrapper.
- Instalar drivers wifi propietarios (Los más comunes y licencia).
- Convertir cararcteres especiales a UTF-8.
- Sustituir espacios en blanco en nombre de archivos por rutas.
- Resetear configuración kde, sin cambios.
- Actualizar kde a idioma español.
- NTFS sin permisos (corrección de bugs).
- Recuperar contraseña de usuario.
- Recuperar ficheros/directorios borrados por accidente.
- Excluir/incluir paquetes a actualizar.
- Añadir usuario a sudo.
- Cargar dirección sop y visualizar evento (Sopcast).
- Consola como root.
- Conversión de .deb a .rpm
- Extraer audio a un video.
- Añadir audio a un video.
- Convertir formatos de audio.
- Ripeado de CD's.
- Convertir formatos de video, incluido contenedor MATROSKA.
- Convertir avi HD a avi Standard.
- Información de librerias de binarios.
- Información de paquetes dependientes.
- Quemador de discos.
- Preparación de compatibilidad con Mageia.
- Agradecimientos.
- Ayuda a comandos consola más usuales.
- Ayuda a programas de consola más usuales.
- Notas de versión.
- Todas las opciones se pueden cancelar en la ventana de información del evento.
- Información detallada y licencias en todas las opciones.
- Ventana de bienvenida.
- Acceso como root.
- Consola incrustada (interna).
y muchisimo mas...xD

* Sun Oct 24 2010 <kapyderi@eresmas.com> 0.6.0.3bdk
- Bugs corregidos
- Solución a problemas conocidos: Recuperar ficheros/directorios borrados por accidente.
- Duplicado de discos completos.
- Montaje de imagenes .iso
- Desmontaje de imagenes .iso
- Duplicado de particiones.
- Creación de imagenes .iso 
- Firmware de las tarjetas wifi mas conocidas. 

* Sat Oct 23 2010 <kapyderi@eresmas.com> 0.5.1.3bdk
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
- Modificación automatica del fichero .lst con la versión de Mandriva/Mageia que se este utilizando Free, One, Flash o Powerpack
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
- Versión en Script/bash y Zenity
