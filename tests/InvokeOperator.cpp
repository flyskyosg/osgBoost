/**
	@file
	@brief Implementation

	@date 2013

	@author
	Ryan Pavlik
	<rpavlik@iastate.edu> and <abiryan@ryand.net>
	http://academic.cleardefinition.com/
	Iowa State University Virtual Reality Applications Center
	Human-Computer Interaction Graduate Program
*/

//          Copyright Iowa State University 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// Internal Includes
#include "Operators.h"
#include "InvokeOperator.h"
#include "ConstructOperation.h"
#include "testmain.h"

// Library/third-party includes
// - none

// Standard includes
// - none


typedef construct_operation<UnaryMinus, osg::Vec3d>::type MyUnaryOperation;
typedef construct_operation<Addition, osg::Vec3d, osg::Vec3d>::type MyBinaryOperation;

BOOST_MPL_ASSERT((is_same<get_operation_invoker<MyUnaryOperation>::type, UnaryOperatorImplementation<UnaryMinus, osg::Vec3d>::type >));
BOOST_MPL_ASSERT((is_same<get_operation_invoker<MyBinaryOperation>::type, BinaryOperatorImplementation<Addition, osg::Vec3d, osg::Vec3d>::type >));


