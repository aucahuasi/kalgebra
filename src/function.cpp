/*************************************************************************************
 *  Copyright (C) 2007 by Aleix Pol <aleixpol@gmail.com>                             *
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

#include "function.h"
#include "exp.h"

#include <klocale.h>
#include "variables.h"
#include "analitza.h"
#include "expression.h"
#include "functionimpl.h"

function::function()
	: m_function(0), m_show(true), m_selected(false), m_color(Qt::black)
{}

function::function(const QString &name, const Expression& newFunc, const QColor& color, bool selec)
	: m_function(0), m_show(true), m_selected(selec), m_color(color), m_name(name)
{
	QStringList bvars=newFunc.bvarList();
	QString firstBVar=bvars.isEmpty() ? "x" : bvars[0];
	if(firstBVar=="x")
		m_function=new FunctionY(newFunc);
	else if(firstBVar=="y")
		m_function=new FunctionX(newFunc);
	else if(firstBVar=="q")
		m_function=new FunctionPolar(newFunc);
	else
		m_err << "Function type not recognized";
}

/*FunctionImpl* copy(FunctionImpl* fi)
{
	FunctionX *fx;
	FunctionY *fy;
	FunctionPolar *fp;
	if(fx=dynamic_cast<FunctionX*>(fi))
		return new FunctionX(*fx);
	else if(fy=dynamic_cast<FunctionY*>(fi))
		return new FunctionY(*fy);
	else if(fp=dynamic_cast<FunctionPolar*>(fi))
		return new FunctionPolar(*fp);
	else 
		return 0;
}*/

function::function(const function& f)
	: m_function(0), m_show(f.m_show), m_selected(f.m_selected), m_color(f.m_color), m_name(f.m_name)
{
	m_function=f.m_function->copy();
}

function::~function()
{
	if(m_function)
		delete m_function;
}

function function::operator=(const function& f)
{
	if(&f!=this) {
		if(m_function)
			delete m_function;
		
		m_function=f.m_function->copy();
// 		m_function=copy(f.m_function);
		Q_ASSERT(m_function);
		m_show=f.m_show;
		m_selected=f.m_selected;
		m_color=f.m_color;
		m_name=f.m_name;
	}
	return *this;
}

void function::update_points(const QRect& viewport, unsigned int max_res)
{
	Q_ASSERT(m_function);
	m_function->updatePoints(viewport, max_res);
}

Axe function::axeType() const
{
	return m_function->axeType();
}

bool function::isShown() const
{
	return m_show && m_function && m_function->isCorrect();
}

double function::derivative(const QPointF & p) const
{
	Q_ASSERT(m_function);
	return m_function->derivative(p);
}

QStringList function::bvars() const
{
	return m_function->bvarList();
}

unsigned int function::npoints() const
{
	return m_function->m_last_resolution;
}

Analitza * function::analitza() const
{
	Q_ASSERT(m_function);
	return &m_function->func;
}

QPointF * function::points() const
{
	return m_function->points;
}

QPair< QPointF, QString > function::calc(const QPointF & dp)
{
	Q_ASSERT(m_function);
	return m_function->calc(dp);
}

bool function::isCorrect() const
{
	return m_function && m_err.isEmpty() && m_function->isCorrect();
}

QString function::toString() const
{
	return m_function->toString();
}
