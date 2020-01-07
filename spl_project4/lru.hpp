//
// Created by 10578 on 1/7/2020.
//

#ifndef COMPILERS_LRU_HPP
#define COMPILERS_LRU_HPP

#include <vector>
#include <set>
#include <algorithm>

namespace SPL {

	template<typename T>
	class LRUAllocator {
	public:
		explicit LRUAllocator(int cache_size) : cache_size{cache_size} {};

		T touch(const T &x);

	private:
		// store keys of cache
		std::vector<T> dq;

		std::set<T> element_set;

		int cache_size; // maximum capacity of cache
	};

	/**
	 * Touch x.
	 * @tparam T
	 * @param x nullptr means get a register to be replaced, or only update the cache
	 * @return nullptr if replacement is not needed, replaced pointer if needed
	 */
	template<typename T>
	T LRUAllocator<T>::touch(const T &x) {
		T replaced = nullptr;

		if (x == nullptr) {
			if (dq.size() != cache_size) {
				std::cout << "here" << std::endl;
			}

			replaced = dq.back();
			dq.pop_back();
			dq.insert(dq.begin(), replaced);
		} else {
			// present in cache
			dq.erase(std::remove(dq.begin(), dq.end(), x), dq.end());

			dq.insert(dq.begin(), x);
			element_set.insert(x);
		}

		return replaced;
	}
}

#endif //COMPILERS_LRU_HPP
