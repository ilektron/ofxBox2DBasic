#include "ofxB2Draw.h"
#include "ofMain.h"

using namespace box2d;

constexpr double COLOR_SCALE = 255.0f;

void ofxB2Draw::DrawPolygon(const std::vector<b2Vec2>& vertices, const b2Color& color)
{
	ofPushStyle();
	ofNoFill();
	ofSetColor(color.r * COLOR_SCALE, color.g * COLOR_SCALE, color.b * COLOR_SCALE, color.a * COLOR_SCALE);
	ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofBeginShape();
    for (auto& vertex : vertices)
    {
        //      ofVertex(vertices[i][b2VecX] * OFXB2DBASIC_WORLD_SCALE, vertices[i][b2VecY] * OFXB2DBASIC_WORLD_SCALE);
        ofVertex(vertex[b2VecX], vertex[b2VecY]);
    }
	ofEndShape();
	
	ofPopStyle();
}

void ofxB2Draw::DrawSolidPolygon(const std::vector<b2Vec2>& vertices, const b2Color& color)
{
	ofPushStyle();
	ofSetColor(color.r * COLOR_SCALE, color.g * COLOR_SCALE, color.b * COLOR_SCALE, color.a * COLOR_SCALE);
	ofFill();
	ofBeginShape();
	for (auto& vertex : vertices)
	{
// 		ofVertex(vertices[i][b2VecX] * OFXB2DBASIC_WORLD_SCALE, vertices[i][b2VecY] * OFXB2DBASIC_WORLD_SCALE);
		ofVertex(vertex[b2VecX], vertex[b2VecY]);
	}
	ofEndShape();
	
	ofPopStyle();
}

void ofxB2Draw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
{
	ofPushStyle();
	ofSetColor(color.r * COLOR_SCALE, color.g * COLOR_SCALE, color.b * COLOR_SCALE, color.a * COLOR_SCALE);
	ofNoFill();
// 	ofDrawCircle(center[b2VecX] * OFXB2DBASIC_WORLD_SCALE, center[b2VecY] * OFXB2DBASIC_WORLD_SCALE, radius * OFXB2DBASIC_WORLD_SCALE);
    ofDrawCircle(center[b2VecX], center[b2VecY], radius);
	ofPopStyle();
}

void ofxB2Draw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
{
	ofPushStyle();
	ofSetColor(color.r * COLOR_SCALE, color.g * COLOR_SCALE, color.b * COLOR_SCALE, color.a * COLOR_SCALE);
	ofFill();
// 	ofDrawCircle(center[b2VecX] * OFXB2DBASIC_WORLD_SCALE, center[b2VecY] * OFXB2DBASIC_WORLD_SCALE, radius * OFXB2DBASIC_WORLD_SCALE);
    ofDrawCircle(center[b2VecX], center[b2VecY], radius);
	ofPopStyle();
}

void ofxB2Draw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
	ofPushStyle();
	ofSetColor(color.r * COLOR_SCALE, color.g * COLOR_SCALE, color.b * COLOR_SCALE, color.a * COLOR_SCALE);
	ofFill();
// 	ofDrawLine(p1[b2VecX] * OFXB2DBASIC_WORLD_SCALE, p1[b2VecY] * OFXB2DBASIC_WORLD_SCALE, p2[b2VecX] * OFXB2DBASIC_WORLD_SCALE, p2[b2VecY] * OFXB2DBASIC_WORLD_SCALE);
    ofDrawLine(p1[b2VecX] , p1[b2VecY], p2[b2VecX], p2[b2VecY]);
	ofPopStyle();
}

void ofxB2Draw::DrawTransform(const b2Transform& xf)
{
	
	const float length = 1;
    b2Vec2 start = xf.p;
    b2Vec2 axis = xf.q.GetXAxis();
    b2Vec2 end = start + b2Vec2{{axis[b2VecX] * length, axis[b2VecY] * length}};
	
	DrawSegment(start, end, b2Color(0,1,0));
	
// 	b2Vec2 p1 = xf.p;
// 	b2Vec2 p2;
// 	const float32 k_axisScale = 0.4f;
// 
// 	p2[b2VecX] = p1[b2VecX] + k_axisScale * xf.q.GetXAxis()[b2VecX];
// 	p2[b2VecY] = p1[b2VecY] + k_axisScale * xf.q.GetXAxis()[b2VecY];
// 	DrawSegment(p1,p2,b2Color(1,0,0));
	
// 	p2[b2VecX] = p1[b2VecX] + k_axisScale * xf.q.GetYAxis()[b2VecX];
// 	p2[b2VecY] = p1[b2VecY] + k_axisScale * xf.q.GetYAxis()[b2VecY];
// 	DrawSegment(p1,p2,b2Color(0,1,0));
}

void ofxB2Draw::DrawPoint(const b2Vec2& p, float32 size, const b2Color& color)
{
    DrawCircle(p, size, color);
    
}

void ofxB2Draw::DrawAABB(const b2AABB& aabb, const b2Color& color)
{
    b2Vec2 p1 = aabb.lowerBound;
    b2Vec2 p2 = {{aabb.upperBound[b2VecX], aabb.lowerBound[b2VecY]}};
    b2Vec2 p3 = aabb.upperBound;
    b2Vec2 p4 = {{aabb.lowerBound[b2VecX], aabb.upperBound[b2VecY]}};
    
    DrawSegment(p1, p2, color);
    DrawSegment(p2, p3, color);
    DrawSegment(p3, p4, color);
    DrawSegment(p4, p1, color);
}

void ofxB2Draw::DrawString(const b2Vec2& p, string s)
{
    ofSetColor(255, 130, 130, 255);
    ofDrawBitmapString(s, p[b2VecX], p[b2VecY]);
}


