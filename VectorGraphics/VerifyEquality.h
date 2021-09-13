#pragma once

template<typename T>
static void verifyEquality(T parameter1, T parameter2, const std::string& exception)
{
	if (parameter1 != parameter2)
	{
		throw std::runtime_error(exception);
	}
}
