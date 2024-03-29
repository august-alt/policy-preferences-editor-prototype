find_package(MVVM REQUIRED)

find_package(PREFERENCES_EDITOR COMPONENTS core io model REQUIRED)
include_directories(${PREFERENCES_EDITOR_INCLUDE_DIRS})

find_package(Qt5 COMPONENTS Core REQUIRED)

set(PLUGIN_NAME administrative-templates-plugin)

include_directories("${CMAKE_SOURCE_DIR}/src/core")

set(HEADERS
    administrativetemplatessnapin.h
    admx/category.h
    admx/majorversion.h
    admx/minorversion.h
    admx/policybooleanelement.h
    admx/policydecimalelement.h
    admx/policydefinitions.h
    admx/policyelement.h
    admx/policyenumelement.h
    admx/policy.h
    admx/policyitem.h
    admx/policylistelement.h
    admx/policylongdecimalelement.h
    admx/policymultitextelement.h
    admx/policytextelement.h
    admx/policytype.h
    admx/registryvalue.h
    admx/registryvaluetype.h
    admx/resources.h
    admx/supporteddefinition.h
    admx/supportedon.h
    admx/supportedproduct.h
    bundle/itemtype.h
    bundle/policybundle.h
    bundle/policyroles.h
    bundle/policytreemodel.h
    bundle/policytreemodelitem.h
    commands/command.h
    commands/commandgroup.h
    presentation/checkbox.h
    presentation/combobox.h
    presentation/decimaltextbox.h
    presentation/dropdownlist.h
    presentation/listbox.h
    presentation/longdecimaltextbox.h
    presentation/multitextbox.h
    presentation/policyresources.h
    presentation/presentation.h
    presentation/presentationwidget.h
    presentation/presentationwidgetvisitor.h
    presentation/textbox.h
    presentation/text.h
    registry/abstractregistryentry.h
    registry/abstractregistrysource.h
    registry/policystatemanager.h
    registry/polregistrysource.h
    registry/registry.h
    registry/registryentry.h
    registry/registryentrytype.h
    registry/registrysourcetype.h
)

set(SOURCES
    administrativetemplatessnapin.cpp
    administrativetemplatesplugin.cpp
    bundle/policybundle.cpp
    commands/command.cpp
    commands/commandgroup.cpp
    presentation/presentationwidget.cpp
    registry/abstractregistrysource.cpp
    registry/policystatemanager.cpp
    registry/polregistrysource.cpp
)

set(SOURCES ${SOURCES} ${HEADERS})

add_preferences_editor_plugin(${PLUGIN_NAME} ${SOURCES})
target_link_libraries(${PLUGIN_NAME} Qt5::Core)
target_link_libraries(${PLUGIN_NAME} ${PREFERENCES_EDITOR_LIBRARIES})
