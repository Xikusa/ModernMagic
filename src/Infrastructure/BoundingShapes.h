﻿//////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2008-2013, Shane Liesegang
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
// 
//     * Redistributions of source code must retain the above copyright 
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright 
//       notice, this list of conditions and the following disclaimer in the 
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the copyright holder nor the names of any 
//       contributors may be used to endorse or promote products derived from 
//       this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.
//////////////////////////////////////////////////////////////////////////////

#pragma once

#include "../Infrastructure/Vector2.h"

MM_BEGIN

struct Ray2;

enum class ContainmentType
{
	Disjoint,
	Within,
	Intersects
};

struct BoundingBox
{
	Vector2 Min;
	Vector2 Max;

	BoundingBox(const Vector2& min, const Vector2& max);
	BoundingBox() {}

	Vector2 Centroid() const;
	Vector2 HalfLength() const;

	static BoundingBox CreateMerged(const BoundingBox& original, const BoundingBox& additional);

	void GetCorners(Vector2 corners[]) const;
	static BoundingBox CreateFromPoints(Vector2 points[], int count);

	bool Intersects(const BoundingBox& box) const;
	bool Intersects(const Ray2& ray, float& distanceAlongRay) const;
	bool Intersects(const Vector2& point, float radius) const;
	bool Intersects(const Vector2 &point) const {
		bool blResult = (point.X >= Min.X && point.X <= Max.X) &&
			(point.Y >= Min.Y && point.Y <= Max.Y);
		return blResult;
	}

	ContainmentType Contains(const BoundingBox& box) const;
	bool Contains(const Vector2& point) const;
};


bool operator ==(const BoundingBox& a, const BoundingBox& b);
bool operator !=(const BoundingBox& a, const BoundingBox& b);

MM_END