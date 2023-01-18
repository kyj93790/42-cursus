#ifndef DATA_HPP
# define DATA_HPP

# include <string>

class Data {
	private:
		std::string _id;
		int _num;
		Data();
	public:
		Data(std::string id, int num);
		Data(const Data& data);
		~Data();
		const Data& operator=(const Data& data);
		std::string getId() const;
		int getNum() const;
};

#endif