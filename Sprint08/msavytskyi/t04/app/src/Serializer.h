#pragma once

#include <iostream>
#include <fstream>
#include <typeinfo> 
#include <string> 


class Serializer {
public:
	template<class T>
	void serialize(const T* object, const std::string& fileName) {
		std::ofstream ofs (fileName, std::ios::binary);
		ofs.write(reinterpret_cast<const char*>(object), sizeof(T));
		ofs.close();
	}

	template<class T>
	T deserialize(const std::string& fileName) {
		T object;
		std::ifstream ifs (fileName, std::ios::binary);
		ifs.read(reinterpret_cast<char*>(&object), sizeof(T));
		ifs.close();
		
		return object;
	}
};
