#pragma once

#include <vector>

namespace AnyCAD{ namespace API{

   typedef float Real;
   typedef void* Handle;
   /**
   * @ingroup Common
   * @author AnyCAD
   * @brief
   *    Point or vector
   */
   class AnyPlatformAPI_API Vector2
   {
   public:
      Real x;
      Real y;
   public:
      Vector2()
         :x(0), y(0)
      
      {}
      Vector2(Real _x, Real _y)
         :x(_x), y(_y)
      {}
   };
   typedef std::vector<Vector2> Vector2List;
   /**
   * @ingroup Common
   * @author AnyCAD
   * @brief
   *    Point or vector
   */
   class AnyPlatformAPI_API Vector3
   {
   public:
      Real x;
      Real y;
      Real z;
   public:
      Vector3()
         :x(0), y(0), z(0)
      
      {}
      Vector3(Real _x, Real _y, Real _z)
         :x(_x), y(_y), z(_z)
      {}

      /**
      *  a - b
      */
      Vector3 operator-(const Vector3& rhv) const
      {
         return Vector3(x-rhv.x, y-rhv.y, z-rhv.z);
      }
      /**
      *  a + b
      */
      Vector3 operator+(const Vector3& rhv) const
      {
         return Vector3(x+rhv.x, y+rhv.y, z+rhv.z);
      }
      /**
      *  a * b
      */
      Vector3 operator*(const Vector3& rhv) const
      {
         return Vector3(x*rhv.x, y*rhv.y, z*rhv.z);
      }
      /**
      *  a * int
      */
      Vector3 operator*(Real vv) const
      {
         return Vector3(x*vv, y*vv, z*vv);
      }
      /**
      *  a / int
      */
      Vector3 operator/(Real vv) const
      {
         return Vector3(x/vv, y/vv, z/vv);
      }
      /**
      *  the length of the vector
      */   
      Real length() const;
      /**
      *  the distance between two points
      */   
      Real distance(const Vector3& pt) const;
      /**
      *  the dot product of the two points
      */   
      Real dotProduct(const Vector3& pt) const;
     /**
      *  normalize the vector to be UNIT vector, return the original length
      */  
      Real normalize();

      /**
      *  the cross product of the two points
      */ 
      Vector3 crossProduct(const Vector3& pt) const;
      /**
      *  the angle between two vectors
      */  
      Real angleBetween(const Vector3& vv) const;
     /**
      *  the angle between up
      *@param angleZ the angle rotate around z axis
      */  
      Vector3 angleBetweenZUp(Real angleZ) const;

   public:
       static const Vector3 ZERO;
       static const Vector3 UNIT_X;
       static const Vector3 UNIT_Y;
       static const Vector3 UNIT_Z;
   };
   /**
   * @ingroup Common
   * @author AnyCAD
   * @brief
   *    Point of vector list
   */
   class  AnyPlatformAPI_API Vector3List
   {
   public:
      typedef std::vector<Vector3> Vector3Arr;

      /**
      * Get list size
      */
      int      size() const { return int(m_arr.size());}
      /**
      * Add Vector3
      *@param vec new element
      */
      void     add(const Vector3& vec);

      /**
      * Get Vector3
      *@param idx the index
      */
      Vector3  get(int idx) const;


      Vector3* ptr() { return &m_arr[0]; }
      /**
      * Get element by index
      *@param vec new element
      */
      const Vector3& operator[] (int idx) const
      {
         return m_arr[idx];
      }

      void resize(int nSize){ m_arr.resize(nSize); }

   public:
      const Vector3Arr& GetImpl() const  {return m_arr; }
      Vector3Arr& GetImpl() { return m_arr; }

   protected:
      Vector3Arr m_arr;
   };
   /**
   * @ingroup Common
   * @author AnyCAD
   * @brief
   *    Color Value
   */
   class AnyPlatformAPI_API ColorValue
   {
   public:
      Real r;
      Real g;
      Real b;
      Real a;
   public:
      ColorValue()
         : r(0), g(0), b(0), a(0)
      {

      }
      ColorValue(Real _r, Real _g, Real _b, Real _a)
         : r(_r), g(_g), b(_b), a(_a)
      {

      }
      ColorValue(int _r, int _g, int _b, int _a = 255)
          :r(_r/255.0f), g(_g/255.0f), b(_b/255.0f), a(_a/255.0f)
      {

      }

	  long AsRGB() const
	  {
		  return ((long)(((unsigned char)(r*255)|((unsigned short)((unsigned char)(g*255))<<8))|(((unsigned char)(unsigned short)(b*255))<<16)));
	  }
   };
   /**
   * @ingroup Common
   * @author AnyCAD
   * @brief
   *    Matrix3
   */
   class AnyPlatformAPI_API Matrix3
   {
   public:
      Real m[3][3];

   public:
      Matrix3()
      {
      }

      Real Get(int row, int col) const
      {
         return m[row][col];
      }

      void Set(int row, int col, Real data)
      {
         m[row][col] = data;
      }
      inline Real* operator[] (size_t iRow) const
      {
         return (Real*)m[iRow];
      }
   };
   /**
   * @ingroup Common
   * @author AnyCAD
   * @brief
   *    Matrix4
   */
   class AnyPlatformAPI_API Matrix4
   {
   public:
      Real m[4][4];
   public:
      Matrix4()
      {

      }
      Real Get(int row, int col) const
      {
         return m[row][col];
      }

      void Set(int row, int col, Real data)
      {
         m[row][col] = data;
      }
      inline Real* operator[] (size_t iRow) const
      {
         return (Real*)m[iRow];
      }

      Vector3 operator * ( const Vector3 &pt ) const{ return transform(pt); }

      Vector3 transform(const Vector3& pt) const;
   };
   /**
   * @ingroup Common
   * @author AnyCAD
   * @brief
   *    AABox
   */
   class AnyPlatformAPI_API AABox
   {
   public:
      Vector3 minPt;
      Vector3 maxPt;
   public:
      AABox(){}
      AABox(const Vector3& _minPt, const Vector3& _maxPt)
         : minPt(_minPt), maxPt(_maxPt)
      {

      }

      Vector3 GetSize() const { return maxPt - minPt; }

      Vector3 GetCenter() const {return (maxPt+minPt)/2; }

      bool intersects(const AABox& b2) const;

      bool intersects(const Vector3& v) const;

      void transform(const Matrix4& trf);

	  void Merge(const AABox& b2);
   };

   /**
   * @ingroup Common
   * @author AnyCAD
   * @brief
   *    Quaternion
   */
   class AnyPlatformAPI_API Quaternion
   {
   public:
      Real w;
      Real x;
      Real y;
      Real z;
   public:
      Quaternion():w(1.0),x(0),y(0),z(0){}
      Quaternion(Real _w, Real _x, Real _y, Real _z):w(_w),x(_x),y(_y),z(_z){}

      /**
      * From angel and axis.
      * @param rfAngle the degree
      * @param rkAxis the axis
      */
      void FromAngleAxis(const Real& rfAngle, const Vector3& rkAxis);

      /**
      * To Euler angles.
      * @return the angles. (Degree)
      */
      Vector3 ToEulerAnglesXYZ() const;

      /**
      * Rotate the vector
      * @param vec the vector
      * @return the new vector
      */
      Vector3 operator*(const Vector3& vec) const;
   };

   typedef std::pair<bool, Real> RayResult;

   /**
   * @ingroup Common
   * @author AnyCAD
   * @brief
   *    Ray
   */
   class AnyPlatformAPI_API Ray
   {
   public:
       Ray();
       Ray(const Vector3& origin, const Vector3& direction)
           :mOrigin(origin), mDirection(direction) {}

        /** 
         * Sets the origin of the ray. 
         */
        void setOrigin(const Vector3& origin) {mOrigin = origin;} 
        /** 
        * Gets the origin of the ray. 
        */
        const Vector3& getOrigin(void) const {return mOrigin;} 

        /** 
        * Sets the direction of the ray. 
        */
        void setDirection(const Vector3& dir) {mDirection = dir;} 
        /** 
          * Gets the direction of the ray. 
          */
        const Vector3& getDirection(void) const {return mDirection;} 

        /** 
         * Gets the position of a point t units along the ray. 
         */
        Vector3 getPoint(Real t) const { 
            return Vector3(mOrigin + (mDirection * t));
        }

        /** 
         * Gets the intersection point of the the ray and the plane.
         * @param pos the plane position
         * @param dir the plane direction.
         * @return the hit information.
         */
        RayResult Intersect(const Vector3& pos, const Vector3& dir) const;

   protected:
       Vector3 mOrigin;
       Vector3 mDirection;
   };


   /**
   * @ingroup Common
   * @author AnyCAD
   * @brief
   *    Coordinate
   */
   class AnyPlatformAPI_API Coordinate3
   {
   public:
	   Coordinate3();
	   Coordinate3(const Vector3& o, const Vector3& x, const Vector3& y, const Vector3& z);
	   ~Coordinate3();

   public:
	   Vector3 Origion;
	   Vector3 X;
	   Vector3 Y;
	   Vector3 Z;
   };
}}
