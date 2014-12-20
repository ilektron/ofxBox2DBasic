#pragma once
#ifndef OFXB2DRAW_H_
#define OFXB2DRAW_H_

// #include "Box2D/Box2D.h"
#include "box2d11/Box2D/Box2D.h"

#include <sstream>

constexpr double OFXB2DBASIC_WORLD_SCALE = 25.0f;
// constexpr double OFXB2DBASIC_WORLD_SCALE = 1.0f;

class ofxB2Draw : public box2d::b2Draw
{
public:
    ofxB2Draw() = default;
    virtual ~ofxB2Draw() = default;
    
    // Overridden functions that are used during box2d::b2World::Step
    void DrawPolygon(const std::vector<box2d::b2Vec2>& vertices, const box2d::b2Color& color) override;
    void DrawSolidPolygon(const std::vector<box2d::b2Vec2>& vertices, const box2d::b2Color& color) override;
    void DrawCircle(const box2d::b2Vec2& center, box2d::float32 radius, const box2d::b2Color& color) override;
    void DrawSolidCircle(const box2d::b2Vec2& center, box2d::float32 radius, const box2d::b2Vec2& axis, const box2d::b2Color& color) override;
    void DrawSegment(const box2d::b2Vec2& p1, const box2d::b2Vec2& p2, const box2d::b2Color& color) override;
    void DrawTransform(const box2d::b2Transform& xf) override;
    
    // Extra functions
    void DrawPoint(const box2d::b2Vec2& p, box2d::float32 size, const box2d::b2Color& color);
    template<typename ...Ts>
    void DrawString(const box2d::b2Vec2& p, Ts&& ... ts)
    {
        std::string text = DrawStringHelper(std::forward<Ts>(ts)...);
        DrawString(p, text);
    }
    
    void DrawString(const box2d::b2Vec2& p, std::string);
    void DrawAABB(const box2d::b2AABB& aabb, const box2d::b2Color& color);
    
private:
    
    template<typename T>
    std::string DrawStringHelper(T&& t)
    {
        std::stringstream s;
        s << t;
        return s.str();
    }
    
    template<typename T, typename ...Ts>
    std::string DrawStringHelper(T t, Ts&& ...ts)
    {
        std::stringstream s;
        s << t << DrawStringHelper(std::forward<Ts>(ts)...);
        return s.str();
    }
    
};

#endif
