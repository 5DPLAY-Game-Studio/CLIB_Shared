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

#ifndef NET_PLAY5D_UTILS_JSONUTILS_H
#define NET_PLAY5D_UTILS_JSONUTILS_H

#ifndef JSON_RESOURCE_TYPE
#define JSON_RESOURCE_TYPE L"JSON"
#endif


//////////////////////////////////////////////////
// 头文件

#include <windows.h>
#include "nlohmann/json.hpp"

//////////////////////////////////////////////////



//////////////////////////////////////////////////
// 类声明

namespace net::play5d::utils {

/**
 * @brief JSON 工具类
 */
class JsonUtils {
public:

    /**
     * @brief 从资源加载 JSON 字符串
     *
     * @param hInstance 应用实例句柄
     * @param resId 资源 ID
     * @return JSON 字符串
     */
    static
    nlohmann::json
    loadJsonFromResource(
            HINSTANCE hInstance,
            int resId
    );

};
}

#endif //NET_PLAY5D_UTILS_JSONUTILS_H
