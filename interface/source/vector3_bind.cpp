/*     __ __              _ 
 *    / // /_____ ____   (_)
 *   / // // ___// __ \ / / 
 *  / // // /__ / /_/ // /  
 * /_//_/ \___/ \____//_/   
 * https://bitbucket.org/galaktor/llcoi 
 * copyright (c) 2011, llcoi Team
 * MIT license applies - see file "LICENSE" for details.
*/
#include "vector3_bind.h"
#include <OgreVector3.h>

//Vector3::Vector3()

Vector3Handle vector3_create() {
    Ogre::Vector3 *vector3 = new Ogre::Vector3();
    return reinterpret_cast<Vector3Handle>(vector3);
}

void vector3_destroy(Vector3Handle handle) {
    Ogre::Vector3 *vector3 = reinterpret_cast<Ogre::Vector3*>(handle);
    delete vector3;
}

coiReal vector3_x(Vector3Handle handle) {
    Ogre::Vector3 *vector3 = reinterpret_cast<Ogre::Vector3*>(handle);
    return coiReal(vector3->x);
}

coiReal vector3_y(Vector3Handle handle) {
    Ogre::Vector3 *vector3 = reinterpret_cast<Ogre::Vector3*>(handle);
    return coiReal(vector3->y);
}

coiReal vector3_z(Vector3Handle handle) {
    Ogre::Vector3 *vector3 = reinterpret_cast<Ogre::Vector3*>(handle);
    return coiReal(vector3->z);
}

void vector3_set_x(Vector3Handle handle, coiReal real) {
    Ogre::Vector3 *vector3 = reinterpret_cast<Ogre::Vector3*>(handle);
    vector3->x = Ogre::Real(real);
}

void vector3_set_y(Vector3Handle handle, coiReal real) {
    Ogre::Vector3 *vector3 = reinterpret_cast<Ogre::Vector3*>(handle);
    vector3->y = Ogre::Real(real);
}

void vector3_set_z(Vector3Handle handle, coiReal real) {
    Ogre::Vector3 *vector3 = reinterpret_cast<Ogre::Vector3*>(handle);
    vector3->z = Ogre::Real(real);
}

//Vector3::operator !=
int vector3_notequals_vector3(Vector3Handle lhs, Vector3Handle rhs)
{
    Ogre::Vector3 *lhs_bind = reinterpret_cast<Ogre::Vector3*>(lhs);
    Ogre::Vector3 *rhs_bind = reinterpret_cast<Ogre::Vector3*>(rhs);
    return lhs_bind->operator!=(*rhs_bind);
}

//Vector3::operator ==
int vector3_equals_vector3(Vector3Handle lhs, Vector3Handle rhs)
{
    Ogre::Vector3 *lhs_bind = reinterpret_cast<Ogre::Vector3*>(lhs);
    Ogre::Vector3 *rhs_bind = reinterpret_cast<Ogre::Vector3*>(rhs);  
    return lhs_bind->operator==(*rhs_bind);
}

//Vector3::operator +
coiVector3 vector3_add_vector3(Vector3Handle lhs, Vector3Handle rhs)
{
    Ogre::Vector3 *lhs_bind = reinterpret_cast<Ogre::Vector3*>(lhs);
    Ogre::Vector3 *rhs_bind = reinterpret_cast<Ogre::Vector3*>(rhs);  
    Ogre::Vector3 temp = lhs_bind->operator+(*rhs_bind);
    coiVector3 result;
    result.x = temp.x;
    result.y = temp.y;
    result.z = temp.z;
    return result;
}

//Vector3::operator +=
Vector3Handle vector3_update_add_vector3(Vector3Handle lhs, Vector3Handle rhs)
{
    Ogre::Vector3 *lhs_bind = reinterpret_cast<Ogre::Vector3*>(lhs);
    Ogre::Vector3 *rhs_bind = reinterpret_cast<Ogre::Vector3*>(rhs); 
    lhs_bind->operator+=(*rhs_bind); 
    return reinterpret_cast<Vector3Handle>(lhs_bind);
}

//Vector3::operator -
coiVector3 vector3_subtract_vector3(Vector3Handle lhs, Vector3Handle rhs)
{
    Ogre::Vector3 *lhs_bind = reinterpret_cast<Ogre::Vector3*>(lhs);
    Ogre::Vector3 *rhs_bind = reinterpret_cast<Ogre::Vector3*>(rhs);  
    Ogre::Vector3 temp = lhs_bind->operator-(*rhs_bind);
    coiVector3 result;
    result.x = temp.x;
    result.y = temp.y;
    result.z = temp.z;
    return result;
}

//Vector3::operator -=
void vector3_update_subtract_vector3(Vector3Handle lhs, Vector3Handle rhs)
{
    Ogre::Vector3 *lhs_bind = reinterpret_cast<Ogre::Vector3*>(lhs);
    Ogre::Vector3 *rhs_bind = reinterpret_cast<Ogre::Vector3*>(rhs);  
    lhs_bind->operator-=(*rhs_bind);
}

//Vector3::operator - 
coiVector3 vector3_negate(Vector3Handle handle)
{
    Ogre::Vector3 *vec = reinterpret_cast<Ogre::Vector3*>(handle);
    vec->operator-();
    coiVector3 result;
    result.x = vec->x;
    result.y = vec->y;
    result.z = vec->z;
    return result;
}

// Vector3::operator/ 
coiVector3 vector3_divide_vector3(Vector3Handle lhs, Vector3Handle rhs)
{
    coiVector3 result;
    Ogre::Vector3 *lhs_bind = reinterpret_cast<Ogre::Vector3*>(lhs);
    Ogre::Vector3 *rhs_bind = reinterpret_cast<Ogre::Vector3*>(rhs);
    Ogre::Vector3 temp = lhs_bind->operator/(*rhs_bind);
    result.x = temp.x;
    result.y = temp.y;
    result.z = temp.z;
    return result;
}


coiVector3 vector3_multiply_vector3(Vector3Handle lhs, Vector3Handle rhs)
{
    coiVector3 result;
    Ogre::Vector3 *lhs_bind = reinterpret_cast<Ogre::Vector3*>(lhs);
    Ogre::Vector3 *rhs_bind = reinterpret_cast<Ogre::Vector3*>(rhs);
    Ogre::Vector3 temp = lhs_bind->operator*(*rhs_bind);
    result.x = temp.x;
    result.y = temp.y;
    result.z = temp.z;
    return result;
}

coiVector3 vector3_multiply_scalar(Vector3Handle lhs, coiReal rhs)
{
    coiVector3 result;
    Ogre::Vector3 *lhs_bind = reinterpret_cast<Ogre::Vector3*>(lhs);
    Ogre::Vector3 temp = lhs_bind->operator*(rhs);
    result.x = temp.x;
    result.y = temp.y;
    result.z = temp.z;
    return result;
}


int vector3_is_nan(Vector3Handle v3)
{
    Ogre::Vector3 *vector3 = reinterpret_cast<Ogre::Vector3*>(v3);
    return vector3->isNaN();
}

coiVector3 vector3_primary_axis(Vector3Handle v3)
{
    Ogre::Vector3 *vector3 = reinterpret_cast<Ogre::Vector3*>(v3);
    Ogre::Vector3 tmp = vector3->primaryAxis();
    coiVector3 result;
    result.x = tmp.x;
    result.y = tmp.y;
    result.z = tmp.z;

    return result;
}

coiVector3 vector3_ZERO()
{
    Ogre::Vector3 v3(Ogre::Vector3::ZERO);
    coiVector3 result;
    result.x = v3.x;
    result.y = v3.y;
    result.z = v3.z;
    return result;
}

coiVector3 vector3_UNIT_X()
{
    Ogre::Vector3 v3(Ogre::Vector3::UNIT_X);
    coiVector3 result;
    result.x = v3.x;
    result.y = v3.y;
    result.z = v3.z;
    return result;
}

coiVector3 vector3_UNIT_Y()
{
    Ogre::Vector3 v3(Ogre::Vector3::UNIT_Y);
    coiVector3 result;
    result.x = v3.x;
    result.y = v3.y;
    result.z = v3.z;
    return result;
}
coiVector3 vector3_UNIT_Z()
{
    Ogre::Vector3 v3(Ogre::Vector3::UNIT_Z);
    coiVector3 result;
    result.x = v3.x;
    result.y = v3.y;
    result.z = v3.z;
    return result;
}

coiVector3 vector3_NEGATIVE_UNIT_X()
{
    Ogre::Vector3 v3(Ogre::Vector3::NEGATIVE_UNIT_X);
    coiVector3 result;
    result.x = v3.x;
    result.y = v3.y;
    result.z = v3.z;
    return result;
}

coiVector3 vector3_NEGATIVE_UNIT_Y()
{
    Ogre::Vector3 v3(Ogre::Vector3::NEGATIVE_UNIT_Y);
    coiVector3 result;
    result.x = v3.x;
    result.y = v3.y;
    result.z = v3.z;
    return result;
}

coiVector3 vector3_NEGATIVE_UNIT_Z()
{
    Ogre::Vector3 v3(Ogre::Vector3::NEGATIVE_UNIT_Z);
    coiVector3 result;
    result.x = v3.x;
    result.y = v3.y;
    result.z = v3.z;
    return result;
}

coiVector3 vector3_UNIT_SCALE()
{
    Ogre::Vector3 v3(Ogre::Vector3::UNIT_SCALE);
    coiVector3 result;
    result.x = v3.x;
    result.y = v3.y;
    result.z = v3.z;
    return result;
}
