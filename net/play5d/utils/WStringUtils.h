// Copyright (C) 2021-2026, 5DPLAY Game Studio
// All rights reserved.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

//
// Created by liush on 2026/4/5.
//

#ifndef NET_PLAY5D_UTILS_WSTRINGUTILS_H
#define NET_PLAY5D_UTILS_WSTRINGUTILS_H

// 头文件
#include <string>

namespace net::play5d::utils {
/**
 * @brief 宽字符串工具类
 */
class WStringUtils {
public:
    /**
     * @brief UTF-8 字符串转换为宽字符串
     *
     * @param str UTF-8 字符串
     * @return 宽字符串
     */
    static std::wstring utf82wstring(const std::string &str);
};
}

#endif //NET_PLAY5D_UTILS_WSTRINGUTILS_H
