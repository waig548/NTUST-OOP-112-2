/**
 * @brief
 * Please complete the specified requirements described in the problem.
 */
#pragma once

#include <algorithm>
#include <string>

auto& usernameRef = ::username;
auto& passwordRef = ::password;

bool isValidUsername()
{
    if (usernameRef.size() != 8)
        return false;
    if (std::find_if_not(usernameRef.begin(), usernameRef.end(), std::isalpha) != usernameRef.end())
        return false;
    return true;
}

bool isValidPassword()
{
    if (passwordRef.size() < 8)
        return false;
    if (std::find_if_not(passwordRef.begin(), passwordRef.end(), std::isalpha) == passwordRef.end())
        return false;
    return true;
}