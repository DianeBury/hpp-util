// Copyright (C) 2009, 2010 by Thomas Moulard, CNRS.
//
// This file is part of the hppWalkFootPlanner.
//
// hppWalkFootPlanner is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// hppWalkFootPlanner is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with hppWalkFootPlanner.  If not, see <http://www.gnu.org/licenses/>.

#include <cassert>
#include <iomanip>
#include <ostream>

#include "hpp/util/indent.hh"

namespace hpp
{
  inline long& indent (std::ostream& o)
  {
    // The slot to store the current indentation level.
    static const int indent_index = std::ios::xalloc ();
    return o.iword (indent_index);
  }

  std::ostream& incindent (std::ostream& o)
  {
    indent (o) += 2;
    return o;
  }

  std::ostream& decindent (std::ostream& o)
  {
    assert (indent (o));
    indent (o) -= 2;
    return o;
  }

  std::ostream& resetindent (std::ostream& o)
  {
    indent (o) = 0;
    return o;
  }

  std::ostream& iendl (std::ostream& o)
  {
    o << std::endl;
    // Be sure to be able to restore the stream flags.
    char fill = o.fill (' ');
    return o << std::setw (indent (o))
	     << ""
	     << std::setfill (fill);
  }

  std::ostream& incendl (std::ostream& o)
  {
    return o << incindent << iendl;
  }

  std::ostream& decendl (std::ostream& o)
  {
    return o << decindent << iendl;
  }

} // end of namespace hpp.
