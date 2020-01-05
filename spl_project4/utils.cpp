//
// Created by 10578 on 10/10/2019.
//

#include <sstream>
#include <iterator>

#include "utils.hpp"

namespace SPL {

	/**
	* Trim to the str.
	* @param str: string to be trimmed
	* @param ws: whitespace ([ \t] by default)
	* @return
	*/
	std::string trim(const std::string &str, const std::string &ws = " \t") {
		const auto strBegin = str.find_first_not_of(ws);
		if (strBegin == std::string::npos)
			return ""; // no content

		const auto strEnd = str.find_last_not_of(ws);
		const auto strRange = strEnd - strBegin + 1;

		return str.substr(strBegin, strRange);
	}

	std::vector<std::string> split(const std::string &s, const std::string &deli) {
		std::vector<std::string> result;

		size_t last = 0;
		size_t next = 0;
		while ((next = s.find(deli, last)) != std::string::npos) {
			result.emplace_back(s.substr(last, next - last));
			last = next + 1;
		}
		result.emplace_back(s.substr(last));

		return result;
	}
}

