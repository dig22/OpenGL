#pragma once

#include "Test.h"

namespace test
{
class TestClearColor : public Test
{
  public:
    TestClearColor();
    ~TestClearColor();

    void OnUpdate(float daltatime) override;
    void OnRender()  override;
    void OnImGuiRender()  override;

    private:
        float m_ClearColor[4];
};
} // namespace test