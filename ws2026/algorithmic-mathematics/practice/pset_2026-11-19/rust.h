#pragma once
#include <cstdint>
#include <expected>
#include <optional>
#include <string>

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using usize = std::size_t;
using String = std::string;
using str = std::string_view;

template <typename T> using Option = std::optional<T>;

template <typename T, typename E> using Result = std::expected<T, E>;

inline constexpr auto None = std::nullopt;

template <typename T> constexpr auto Some(T value) {
  return Option<T>{std::move(value)};
}

template <typename T> constexpr auto Ok(T value) { return value; }

template <typename E> constexpr auto Err(E error) {
  return std::unexpected<E>{std::move(error)};
}
