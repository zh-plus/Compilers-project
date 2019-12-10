//
// Created by 10578 on 10/10/2019.
//

#include "utils.hpp"

#include <sstream>

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

	/**
	 * Join the elements by separator into a string.
	 * @tparam Iter
	 * @param begin
	 * @param end
	 * @param separator
	 * @return
	 */
	template<typename Iter>
	std::string join(Iter begin, Iter end, std::string const &separator) {
		std::ostringstream result;
		if (begin != end) {
			result << *begin++;
		}

		while (begin != end) {
			result << separator << *begin++;
		}

		return result.str();
	}

	template<typename T>
	std::string join(std::initializer_list<T> seq, std::string const &separator) {
		return join(begin(seq), end(seq), separator);
	}
}

