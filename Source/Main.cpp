// https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf

#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
#include <array>

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

	std::cout << "preprocessed: " << preprocess << std::endl;
	std::cout << std::endl;

	// Setting the Initial Hash Value
	int primeList[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
	int H[8];
	for (int i = 0; i < 8; ++i)
	{
		double x = std::sqrt(primeList[i]);
		x -= static_cast<uint32_t>(x);
		x *= std::pow(16, 8);
		H[i] = static_cast<uint32_t>(x);
		std::cout << "H" << i << ": " << std::hex <<  H[i] << std::endl;
	}
}