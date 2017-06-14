/*************************************************************************************
 *  Copyright (C) 2007-2017 by Aleix Pol <aleixpol@kde.org>                          *
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

#ifndef CONSOLEMODEL_H
#define CONSOLEMODEL_H

#include <QObject>
#include <analitza/expression.h>
#include <analitza/analyzer.h>

class ConsoleModel : public QObject
{
    Q_OBJECT
public:
    /** This enumeration controles the way the console will calculate and show his results. */
    enum ConsoleMode {
        Evaluation, /**< Simplifies the expression, tries to simplify when sees a variable not defined. */
        Calculation /**< Calculates everything, if it finds a not defined variable shows an error. */
    };

    bool addOperation(const Analitza::Expression& e, const QString& input);

    bool loadScript(const QString &path);
    bool saveScript(const QString &path);

Q_SIGNALS:
    void errorMessage(const QString &error);
    void updateView(const QString &newEntry, const Analitza::Expression &result = {});

public:
    Analitza::Analyzer a;
    ConsoleMode m_mode = Evaluation;
    QVector<Analitza::Expression> m_script;
};

#endif