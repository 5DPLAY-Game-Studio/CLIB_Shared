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

//////////////////////////////////////////////////
// 头文件

#include "JsonUtils.h"

//////////////////////////////////////////////////



//////////////////////////////////////////////////
// 类实现

/**
 * @brief 从资源加载 JSON 字符串
 *
 * @param hInstance 应用实例句柄
 * @param resId 资源 ID
 * @return JSON 字符串
  */
nlohmann::json
net::play5d::utils::JsonUtils::
loadJsonFromResource(
        HINSTANCE hInstance,
        int resId
) {
    // 查找资源
    HRSRC hRsrc = FindResourceW(hInstance, MAKEINTRESOURCEW(resId), JSON_RESOURCE_TYPE);
    if (hRsrc == nullptr) {
        return {};
    }

    // 加载资源
    HGLOBAL hResourceData = LoadResource(hInstance, hRsrc);
    if (hResourceData == nullptr) {
        return {};
    }

    // 获取资源大小
    DWORD dwSize = SizeofResource(hInstance, hRsrc);
    if (dwSize == 0) {
        return {};
    }

    // 锁定并解析资源
    const char *pData = (const char *)LockResource(hResourceData);
    if (pData == nullptr) {
        return {};
    }

    // 解析 JSON 字符串
    try {
        return nlohmann::json::parse(pData, pData + dwSize);
    } catch (const nlohmann::json::parse_error& e) {
        return {};
    }
}

//////////////////////////////////////////////////
