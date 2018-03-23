#pragma once

#ifndef _KNOWLEDGE_H
#define _KNOWLEDGE_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <fstream>
#include <string>
#include <random>
#include <vector>
#include <map>
#include <set>

#include "PrintCollection.h"
#include "EXCEPT.h"
#include <time.h>

using std::map;
using std::set;
using std::pair;
using std::string;
using std::vector;

namespace Program {
	enum class is_file_clear { CLEAR = true, DURTY = false };
	using ifc = is_file_clear;

	class Knowledge {
	private:
		map<string, string> not_to_dif; // ������ - �����������
		
		friend string GetOutStrTrash(string);
		friend vector<string> SplitIntoWords(const string&);
		friend bool is_contain(vector<string>, vector<string>);
	public:
		Knowledge() {};
		Knowledge(const Knowledge&);
		Knowledge(const map<string, string>&);
		Knowledge(const string&, ifc is_clear=ifc::DURTY);
		Knowledge& operator=(const Knowledge&);

		Knowledge operator+(const Knowledge&) const noexcept;
		Knowledge& operator+=(const Knowledge&);

		pair<string, string> operator[](size_t) const;

		size_t size() const {
			return not_to_dif.size();
		}

		auto _begin() const{
			return not_to_dif.begin();
		}
		auto _end() const {
			return not_to_dif.end();
		}

		int count(const string&) const;

		map<string, string> find_dif(const string&) const noexcept;

		map<string, string> unde_the_letter(char) const;

		map<string, string> GetSomeNotif(size_t, const set<char>&) const;
		map<string, string> GetSomeNotif(size_t) const;

		void DumpToFile() const noexcept;

		void Add(const pair<string, string>&);
		void Remove(const string&);

		friend void GetOutTrash(const string&, const string&);
		friend bool operator==(const string&, const string&);
		friend std::ostream& operator<<(std::ostream& os, const Knowledge& value) {
			return os << value.not_to_dif;
		}
	};
}
#endif // !_KNOWLEDGE_H