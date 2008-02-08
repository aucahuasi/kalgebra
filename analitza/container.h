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

#ifndef CONTAINER_H
#define CONTAINER_H

#include <QDomNode>

#include "object.h"
#include "operator.h"
#include "analitzaexport.h"

//FIXME: Must move it somewhere
/** Prints a dom tree from a dom node @p in indenting it by @p ind */
void print_dom(const QDomNode& in, int ind);

/** Prints an expression tree from a node @p o indenting it by @p ind */
void objectWalker(const Object* o, int ind=0);

/**
 *	This class is the one that will correspond to MathML container.
 *	e.g. apply, mathml, bvar, uplimit...
 *	@author Aleix Pol <aleixpol@gmail.com>
 */

class ANALITZA_EXPORT Container : public Object
{
public:
	
	/** Is used to describe Container objects in reference to the MathML standard*/
	enum ContainerType {
		none=0, 	/**< No container type, usually means an error */
		math,		/**< Describes a container as a %lt;math&gt; tag */
		apply,		/**< Describes a container as a %lt;apply&gt; tag */
		declare,	/**< Describes a container as a %lt;declare&gt; tag */
		lambda,		/**< Describes a container as a %lt;lambda&gt; tag */
		bvar,		/**< Describes a container as a %lt;bvar&gt; tag */
		uplimit,	/**< Describes a container as a %lt;uplimit&gt; tag */
		downlimit,	/**< Describes a container as a %lt;downlimit&gt; tag */
		piece,		/**< Describes a container as a %lt;piece&gt; tag */
		piecewise,	/**< Describes a container as a %lt;piecewise&gt; tag */
		otherwise,	/**< Describes a container as a %lt;otherwise&gt; tag */
		vector		/**< Describes a container as a %lt;vector&gt; tag */
	};
	
	typedef QList<Object*>::const_iterator const_iterator;
	typedef QList<Object*>::iterator iterator;
	
	/** Constructor. Creates an empty container with no type. */
	Container() : Object(container), m_cont_type(none) { }
	
	/** Construtor. Creates an empty container with @p c type. */
	Container(enum ContainerType c) : Object(container), m_cont_type(c) { }
	
	/** Copy constructor, copies all of the branches derivated on it.*/
	Container(const Container& c);
	
	/** Construtor. If @p o is a Container it is copied, otherwise a cnone container is created. */
	Container(const Object *o);
	
	/** Destructor. Deletes all the references. */
	virtual ~Container() { qDeleteAll(m_params); }
	
	/** Sets the container type to @p c. */
	void setContainerType(enum ContainerType c) { m_cont_type = c; }
	
	/** Returns the type of the container. */
	enum ContainerType containerType() const { Q_ASSERT(m_type==Object::container && m_cont_type!=none); return m_cont_type; }
	
	/** Returns whether @p c is equal or not. */
	bool operator==(const Container& c) const;
	
	/** Converts a @p tag to a containerType. */
	static ContainerType toContainerType(const QString& tag);
	
	/** Returns whether @p o1 is equal to @p o2. */
	static bool equalTree(Object const* o1, Object const * o2);
	
	/** Adds a @p o branch at the end of the Container. */
	void appendBranch(Object* o) { m_params.append(o); }
	
	/** Returns a QStringList where we have all of the bvar in the container */
	QStringList bvarList() const;
	
	/** Returns whether there is any variable inside the tree */
	bool hasVars() const;
	
	/** Returns the first operator found in the container */
	Operator firstOperator() const;
	
	/** Returns an iterator pointing to the first value of the container */
	QList<Object*>::iterator firstValue();
	
	/** Returns a constant iterator pointing to the first value of the container */
	QList<Object*>::const_iterator firstValue() const;
	
	/** Copies all the params to a new list. */
	QList<Object*> copyParams() const;
	
	/** Returns a string representation of the container. */
	QString toString() const;
	
	/** Returns a MathML representation of the container. */
	QString toMathML() const;
	
	/** Returns a Html representation of the container. */
	QString toHtml() const;
	
	/** Returns the container's uplimit. */
	Container* ulimit() const;
	
	/** Returns the container's downlimit. */
	Container* dlimit() const;
	
	/** Returns whether it is an unary container. This means that there is only one value inside. */
	bool isUnary() const;
	
	/** Returns whether it is an empty container. */
	bool isEmpty() const { return firstValue()==m_params.end(); }
	
	/** Returns whether it is correct container. */
	bool isCorrect() const;
	
	/** @return Returns whether it provides a numerical result instead of information. */
	bool isNumber() const;
	
	/** @return Returns the string associated to the container type. */
	QString tagName() const;
	
	virtual void negate();
	
	virtual bool isZero() const;
	
#if 0 //not used
	//Monomials
	/** Creates a monomial, just to ease the construction. */
	Container(Cn* base, Object* var, Ci* degree);
	
	/** Returns the degree of a monomial. */
	static Cn* monomialDegree(const Container&);
	
	/** Returns the base of a monomial. */
	static Cn* monomialBase(const Container&);
	
	/** Returns the base of a monomial. */
	static Object* monomialVar(const Container&);
#endif
// protected:
	QList<Object*> m_params;
private:
	enum ContainerType m_cont_type;
};



#endif