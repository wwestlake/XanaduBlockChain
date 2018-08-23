#ifndef __UTCDATETIME_H
#define __UTCDATETIME_H

#include <string>
#include <boost/program_options.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/local_time_adjustor.hpp>
#include <boost/date_time/c_local_time_adjustor.hpp>


class UTCDateTime {

  std::string today;
  
  UTCDateTime()
  {
    	using boost::posix_time::ptime;
	    using boost::posix_time::second_clock;
	    using boost::posix_time::to_simple_string;
	    using boost::gregorian::day_clock;
	    this->today = to_simple_string(ptime(day_clock::universal_day(), second_clock::universal_time().time_of_day()));
  }

  std::string toString()
  {
      return today;
  }

  
  
};





#endif

