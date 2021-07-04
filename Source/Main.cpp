#include <iostream>
#include <string>
#include <bitset>

int main() {
	// input data
	std::string input;
	std::cin >> input;

	// preprocessing
	int inputLength = input.size() * 8;

	std::string preprocess;
	for (const auto& x : input) {
		std::bitset<8> bit(x);
		preprocess.append(bit.to_string());
	}

	preprocess.append("1");

	int k = (64 + inputLength + 1) / 512;
	k = k * 512 + (512 - 64 - inputLength - 1);
	for (int i = 0; i < k; i++) {
		preprocess.append("0");
	}

	std::bitset<64> bitLength(inputLength);
	preprocess.append(bitLength.to_string());
	std::cout << preprocess;


}