/** @file
	@brief Header

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

#pragma once
#ifndef INCLUDED_OperatorArity_h_GUID_8ff9af97_2009_454d_a842_25a761c96e74
#define INCLUDED_OperatorArity_h_GUID_8ff9af97_2009_454d_a842_25a761c96e74

// Internal Includes
#include "OperatorBase.h"
#include "GetOperator.h"
#include "ArityTags.h"

// Library/third-party includes
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/type_traits/is_same.hpp>


// Standard includes
// - none

namespace osgTraits {

	namespace operator_arity_detail {
		namespace mpl = boost::mpl;

		template<typename Operator>
		struct get_operator_arity {
			typedef typename Operator::arity_tag type;
		};

		/// @brief Metafunction: Gets the arity of an operator or operation.
		template<typename Op>
		struct get_arity {
			typedef typename mpl::eval_if < typename mpl::is_sequence<Op>::type,
			        get_operator<Op>,
			        mpl::identity<Op> >::type Operator;
			typedef typename get_operator_arity<Operator>::type type;
		};

		template<typename Op>
		struct is_unary : boost::is_same<typename get_arity<Op>::type, arity_tags::unary_tag > {};

		template<typename Op>
		struct is_binary : boost::is_same<typename get_arity<Op>::type, arity_tags::binary_tag > {};
	} // end of namespace operator_arity_detail
	using operator_arity_detail::get_arity;
	using operator_arity_detail::is_unary;
	using operator_arity_detail::is_binary;
} // end of namespace osgTraits
#endif // INCLUDED_OperatorArity_h_GUID_8ff9af97_2009_454d_a842_25a761c96e74
