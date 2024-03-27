#pragma once

#include <exception>

template <typename T>
class Array
{
	private:
		T* _elements;
		size_t _size;

	public:
		Array() : _elements(NULL) {
			_elements = new T[0];
			_size = 0;
		}

		~Array() {
			if (_elements)
				delete [] _elements;
			_elements = NULL;
		}

		const Array& operator=(const Array& copy) {
			if (this != &copy) {
				if (_elements != NULL && _size >= 0)
					delete [] _elements;
				_elements = new T[copy.size()];
				for (int i = 0; i < copy.size(); i++)
					_elements[i] = copy._elements[i];
				_size = copy.size();
			}

			return *this;
		}

		Array(const Array& copy) : _elements(NULL) {
			if (this != &copy) {
				_elements = new T[copy.size()];
				for (int i = 0; i < copy.size(); i++)
					_elements[i] = copy._elements[i];
				_size = copy.size();
			}
		}

		Array(const unsigned int n) : _elements(NULL) {
			_elements = new T[n];
			_size = n;
		}

		T& operator[](int idx) {
			if (idx >= _size || idx < 0)
				throw std::exception();
			return _elements[idx];
		}

		size_t size() const {
			return _size;
		}

};