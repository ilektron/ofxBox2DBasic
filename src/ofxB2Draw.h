#pragma once
#ifndef OFXB2DRAW_H_
#define OFXB2DRAW_H_

#include "Box2D/Box2D.h"

constexpr double OFXB2DBASIC_WORLD_SCALE = 25.0f;
// constexpr double OFXB2DBASIC_WORLD_SCALE = 1.0f;

class ofxB2Draw : public b2Draw
{
public:
    ofxB2Draw() = default;
    virtual ~ofxB2Draw() = default;
    
    void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override;
    void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override;
    void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) override;
    void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) override;
    void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) override;
    void DrawTransform(const b2Transform& xf) override;
};

#endif
