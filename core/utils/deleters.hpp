#pragma once

struct NoOpDeleter {
    template <typename T>
    void operator()(T* _) const noexcept {}
};
