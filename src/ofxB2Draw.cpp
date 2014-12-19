#include "ofxB2Draw.h"
#include "ofMain.h"

constexpr double COLOR_SCALE = 255.0f;

void ofxB2Draw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	ofPushStyle();
	ofNoFill();
	ofSetColor(color.r * COLOR_SCALE, color.g * COLOR_SCALE, color.b * COLOR_SCALE, color.a * COLOR_SCALE);
	ofSetPolyMode(OF_POLY_WINDING_NONZERO);
	ofBeginShape();
	for (int i = vertexCount - 1; i >= 0; --i)
	{
// 		ofVertex(vertices[i].x * OFXB2DBASIC_WORLD_SCALE, vertices[i].y * OFXB2DBASIC_WORLD_SCALE);
		ofVertex(vertices[i].x, vertices[i].y);
	}
	ofEndShape();
	
	ofPopStyle();
}

void ofxB2Draw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	ofPushStyle();
	ofSetColor(color.r * COLOR_SCALE, color.g * COLOR_SCALE, color.b * COLOR_SCALE, color.a * COLOR_SCALE);
	ofFill();
	ofBeginShape();
	for (int i = vertexCount - 1; i >= 0; --i)
	{
// 		ofVertex(vertices[i].x * OFXB2DBASIC_WORLD_SCALE, vertices[i].y * OFXB2DBASIC_WORLD_SCALE);
		ofVertex(vertices[i].x, vertices[i].y);
	}
	ofEndShape();
	
	ofPopStyle();
}

void ofxB2Draw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
{
	ofPushStyle();
	ofSetColor(color.r * COLOR_SCALE, color.g * COLOR_SCALE, color.b * COLOR_SCALE, color.a * COLOR_SCALE);
	ofNoFill();
// 	ofDrawCircle(center.x * OFXB2DBASIC_WORLD_SCALE, center.y * OFXB2DBASIC_WORLD_SCALE, radius * OFXB2DBASIC_WORLD_SCALE);
	ofDrawCircle(center.x, center.y, radius);
	ofPopStyle();
}

void ofxB2Draw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
{
	ofPushStyle();
	ofSetColor(color.r * COLOR_SCALE, color.g * COLOR_SCALE, color.b * COLOR_SCALE, color.a * COLOR_SCALE);
	ofFill();
// 	ofDrawCircle(center.x * OFXB2DBASIC_WORLD_SCALE, center.y * OFXB2DBASIC_WORLD_SCALE, radius * OFXB2DBASIC_WORLD_SCALE);
	ofDrawCircle(center.x, center.y, radius);
	ofPopStyle();
}

void ofxB2Draw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
	ofPushStyle();
	ofSetColor(color.r * COLOR_SCALE, color.g * COLOR_SCALE, color.b * COLOR_SCALE, color.a * COLOR_SCALE);
	ofFill();
// 	ofDrawLine(p1.x * OFXB2DBASIC_WORLD_SCALE, p1.y * OFXB2DBASIC_WORLD_SCALE, p2.x * OFXB2DBASIC_WORLD_SCALE, p2.y * OFXB2DBASIC_WORLD_SCALE);
	ofDrawLine(p1.x , p1.y, p2.x, p2.y);
	ofPopStyle();
}

void ofxB2Draw::DrawTransform(const b2Transform& xf)
{
	
	const float length = 1;
    b2Vec2 start = xf.p;
    b2Vec2 axis = xf.q.GetXAxis();
    b2Vec2 end = start + b2Vec2(axis.x * length, axis.y * length);
	
	DrawSegment(start, end, b2Color(0,1,0));
	
// 	b2Vec2 p1 = xf.p;
// 	b2Vec2 p2;
// 	const float32 k_axisScale = 0.4f;
// 
// 	p2.x = p1.x + k_axisScale * xf.q.GetXAxis().x;
// 	p2.y = p1.y + k_axisScale * xf.q.GetXAxis().y;
// 	DrawSegment(p1,p2,b2Color(1,0,0));
	
// 	p2.x = p1.x + k_axisScale * xf.q.GetYAxis().x;
// 	p2.y = p1.y + k_axisScale * xf.q.GetYAxis().y;
// 	DrawSegment(p1,p2,b2Color(0,1,0));
}
