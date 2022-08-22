%define _unpackaged_files_terminate_build 1

Name: preferences_editor
Version: 0.1.0
Release: alt1

Summary: Group policy editor
License: GPLv2+
Group: Other
Url: https://github.com/august-alt/preferences_editor

BuildRequires: cmake
BuildRequires: rpm-macros-cmake
BuildRequires: cmake-modules
BuildRequires: gcc-c++
BuildRequires: qt5-base-devel
BuildRequires: qt5-declarative-devel
BuildRequires: qt5-tools-devel
BuildRequires: libsmbclient-devel libsmbclient

BuildRequires: qt5-base-common
BuildRequires: doxygen
BuildRequires: libxerces-c-devel
BuildRequires: xsd
BuildRequires: boost-devel-headers

BuildRequires: desktop-file-utils ImageMagick-tools

BuildRequires: libqt-mvvm-devel

Requires: admx-basealt

Source0: %name-%version.tar

%description
Group policy editor

%prep
%setup -q

%build
%cmake
%cmake_build

%install
%cmakeinstall_std

cd %_cmake__builddir
desktop-file-install --dir=%buildroot%_desktopdir \
                     --set-key Exec --set-value %_bindir/preferences_editor-main \
                     ../setup/preferences_editor.desktop

for size in 48 64 128 256 512; do
    mkdir -p %buildroot%_datadir/icons/hicolor/''${size}x''${size}/apps/
    convert ../setup/logo_1024_1024.png -resize ''${size}x''${size} \
    %buildroot%_datadir/icons/hicolor/''${size}x''${size}/apps/preferences_editor.png
done

%files
%doc README.md
%doc INSTALL.md
%_bindir/preferences_editor-main
%_bindir/preferences_editor-mvvm-folders

%_libdir/libpreferences_editor-gui.so
%_libdir/libpreferences_editor-io.so
%_libdir/libpreferences_editor-core.so

%_libdir/preferences_editor/plugins/libinifile-plugin.so
%_libdir/preferences_editor/plugins/libpreferences-plugin.so
%_libdir/preferences_editor/plugins/libscripts-plugin.so
%_libdir/preferences_editor/plugins/libsmb-storage-plugin.so
%_libdir/preferences_editor/plugins/libadministrative-templates-plugin.so

%_datadir/icons/hicolor/48x48/apps/preferences_editor.png
%_datadir/icons/hicolor/64x64/apps/preferences_editor.png
%_datadir/icons/hicolor/128x128/apps/preferences_editor.png
%_datadir/icons/hicolor/256x256/apps/preferences_editor.png
%_datadir/icons/hicolor/512x512/apps/preferences_editor.png

%_desktopdir/preferences_editor.desktop

%changelog
* Tue Apr 12 2022 Vladimir Rubanov <august@altlinux.org> 0.1.0-alt1
- Initial build
