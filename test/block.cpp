/**
 *   Copyright (C) 2010, 2011 Object Modeling Designs
 */

#include "../yaml/parser/block_def.hpp"
#include <iostream>
#include <fstream>
#include <string>

#include <boost/spirit/include/classic_position_iterator.hpp>

typedef std::string::const_iterator base_iterator_type;
typedef boost::spirit::classic::position_iterator<base_iterator_type>
    iterator_type;

template struct omd::parser::block<iterator_type>;
