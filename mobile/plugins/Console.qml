/*************************************************************************************
 *  Copyright (C) 2015 by Aleix Pol <aleixpol@kde.org>                               *
 *                                                                                   *
 *  This program is free software; you can redistribute it and/or                    *
 *  modify it under the terms of the GNU General Public License                      *
 *  as published by the Free Software Foundation; either version 2                   *
 *  of the License, or (at your option) any later version.                           *
 *                                                                                   *
 *  This program is distributed in the hope that it will be useful,                  *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of                   *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                    *
 *  GNU General Public License for more details.                                     *
 *                                                                                   *
 *  You should have received a copy of the GNU General Public License                *
 *  along with this program; if not, write to the Free Software                      *
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA   *
 *************************************************************************************/

import org.kde.kirigami 2.5 as Kirigami
import QtQuick 2.2
import QtQuick.Controls 2.5 as QQC2
import QtQml.Models 2.10
import QtQuick.Dialogs 1.0
import org.kde.analitza 1.0
import org.kde.kalgebra.mobile 1.0
import widgets 1.0

KAlgebraPage
{
    id: page
    ListModel { id: itemModel }

    Clipboard {
        id: clipboard
    }

    ConsoleModel {
        id: consoleModel
        variables: app.variables
        onMessage: {
            itemModel.append({ result: msg, expression: result.toString()  })
            input.selectAll()
            view.currentIndex = view.count-1
            view.positionViewAtIndex(view.currentIndex, ListView.Contain)
        }
    }

    FileDialog {
        id: fileDialog
        folder: shortcuts.home
        onAccepted: proceed()

        property var proceed
    }

    contextualActions: [
        Kirigami.Action {
            text: i18n("Load Script...")
            onTriggered: {
                fileDialog.title = text
                fileDialog.proceed = function() { consoleModel.loadScript(fileDialog.fileUrl) }
                fileDialog.nameFilters = [ i18n("Script (*.kal)") ]
                fileDialog.selectExisting = true
                fileDialog.open()
            }
        },
        Kirigami.Action {
            text: i18n("Save Script...")
            onTriggered: {
                fileDialog.title = text
                fileDialog.proceed = function() { consoleModel.saveScript(fileDialog.fileUrl) }
                fileDialog.nameFilters = [ i18n("Script (*.kal)") ]
                fileDialog.selectExisting = false
                fileDialog.open()
            }
        },
        //TODO: Recent scripts
        Kirigami.Action {
            text: i18n("Export Log...")
            onTriggered: {
                fileDialog.title = text
                fileDialog.proceed = function() { consoleModel.saveLog(fileDialog.fileUrl) }
                fileDialog.nameFilters = [ i18n("HTML (*.html)") ]
                fileDialog.selectExisting = false
                fileDialog.open()
            }
        },
        // --
        Kirigami.Action {
            text: consoleModel.mode === ConsoleModel.Calculate ? i18n("Evaluate...") : i18n("Calculate...")
            onTriggered: consoleModel.mode = consoleModel.mode === ConsoleModel.Calculate ? ConsoleModel.Evaluate : ConsoleModel.Calculate
        },
        // --
        Kirigami.Action {
            iconName: "edit-clear-history"
            text: i18n("Clear Log")
            onTriggered: itemModel.clear()
        }
    ]
    
    Kirigami.CardsListView {
        id: view
        model: itemModel

        delegate: Kirigami.Card {
            contentItem: QQC2.Label { text: model.result }

            hiddenActions: [
                QQC2.Action {
                    readonly property string value: result.replace(/<[^>]*>/g, '');
                    text: i18n("Copy \"%1\"", value)
                    icon.name: "edit-copy"
                    onTriggered: {
                        clipboard.content = value
                    }
                }
            ]
            actions: [
                Kirigami.Action {
                    enabled: app.functionsModel().canAddFunction(expression, 2, app.variables)
                    text: i18n("2D Plot")
                    onTriggered: {
                        app.functionsModel().addFunction(expression, 2, app.variables)
                    }
                },
                Kirigami.Action {
                    enabled: app.functionsModel().canAddFunction(expression, 4, app.variables)
                    text: i18n("3D Plot")
                    onTriggered: {
                        app.functionsModel().addFunction(expression, 4, app.variables)
                    }
                }
            ]
        }

        anchors {
            top: parent.top
            bottom: input.top
            left: parent.left
            right: parent.right
        }
    }

    ExpressionInput {
        id: input
        focus: true
        
        Keys.onReturnPressed: {
            consoleModel.addOperation(text)
        }
        
        anchors {
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }
    }
}
