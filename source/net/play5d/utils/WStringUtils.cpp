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

#include "WStringUtils.h"
#include <windows.h>

//////////////////////////////////////////////////



//////////////////////////////////////////////////
// 类实现

/**
 * @brief UTF-8 字符串转换为宽字符串
 *
 * @param str UTF-8 字符串
 * @return 宽字符串
 */
std::wstring
net::play5d::utils::WStringUtils::
utf82wstring(
        const std::string &str
) {
    // 字符串是否为空
    if (str.empty()) {
        return {};
    }
    // 字符串长度是否超过 INT_MAX
    if (str.size() > INT_MAX) {
        return {};
    }

    // 安全获取输入数据的指针（不依赖自动计算 \0，避免越界）
    const char *const utf8Data = str.data();
    // 安全获取输入数据的长度（不依赖自动计算 \0，避免越界）
    const int utf8ByteLen = static_cast<int>(str.size());

    // 第一次调用
    // 计算所需宽字符长度（不含自动添加的 \0，更安全）
    const int requiredWCharLen = MultiByteToWideChar(
            // 编码页
            CP_UTF8,
            // 遇到非法 UTF-8 直接失败，不生成乱码
            MB_ERR_INVALID_CHARS,
            // 输入数据指针
            utf8Data,
            // 传入显式长度，不依赖字符串结束符
            utf8ByteLen,
            // 输出数据指针
            nullptr,
            // 输出数据长度
            0
    );

    // 检查转换是否成功，长度 <=0 说明编码非法/系统错误
    if (requiredWCharLen <= 0) {
        return {};
    }

    // 分配缓冲区（严格按需要长度创建，无多余内存）
    std::wstring result(requiredWCharLen, L'\0');

    // 第二次调用
    // 执行真正转换
    const int convertedChars = MultiByteToWideChar(
            // 编码页
            CP_UTF8,
            // 遇到非法 UTF-8 直接失败，不生成乱码
            MB_ERR_INVALID_CHARS,
            // 输入数据指针
            utf8Data,
            // 传入显式长度，不依赖字符串结束符
            utf8ByteLen,
            // 输出数据指针
            result.data(),
            // 输出数据长度
            requiredWCharLen
    );

    // 检查转换是否成功，长度 <= 0 说明转换失败
    if (convertedChars <= 0) {
        return {};
    }

    // 返回正确结果字符串（无多余\0）
    return result;
}

//////////////////////////////////////////////////