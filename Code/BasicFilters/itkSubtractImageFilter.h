/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkSubtractImageFilter.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

Copyright (c) 2001 Insight Consortium
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

 * The name of the Insight Consortium, nor the names of any consortium members,
   nor of any contributors, may be used to endorse or promote products derived
   from this software without specific prior written permission.

  * Modified source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER AND CONTRIBUTORS ``AS IS''
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/
#ifndef __itkSubtractImageFilter_h
#define __itkSubtractImageFilter_h

#include "itkBinaryFunctorImageFilter.h"

namespace itk
{
  
/** \class SubtractImageFilter
 * \brief Implements an operator for pixel-wise substraction of two images.
 *
 * This class is parametrized over the types of the two 
 * input images and the type of the output image. 
 * Numeric conversions (castings) are done by the C++ defaults.
 *
 * \ingroup IntensityImageFilters Multithreaded
 */
namespace Function {  
  
  template< class TInput1, class TInput2, class TOutput>
  class Sub2
  {
  public:
    Sub2() {}
    ~Sub2() {}
    inline TOutput operator()( const TInput1 & A, const TInput2 & B)
      { return (TOutput)(A - B); }
  }; 
}

template <class TInputImage1, class TInputImage2, class TOutputImage>
class ITK_EXPORT SubtractImageFilter :
    public
    BinaryFunctorImageFilter<TInputImage1,TInputImage2,TOutputImage, 
    Function::Sub2< 
              typename TInputImage1::PixelType, 
              typename TInputImage2::PixelType,
              typename TOutputImage::PixelType>   >
{
public:
  /** Standard class typedefs. */
  typedef SubtractImageFilter  Self;
  typedef BinaryFunctorImageFilter<TInputImage1,TInputImage2,TOutputImage, 
    Function::Sub2< typename TInputImage1::PixelType, 
                    typename TInputImage2::PixelType,
                    typename TOutputImage::PixelType> >  Superclass;
  typedef SmartPointer<Self>   Pointer;
  typedef SmartPointer<const Self>  ConstPointer;


  /** Method for creation through the object factory. */
  itkNewMacro(Self);
  
protected:
  SubtractImageFilter() {}
  virtual ~SubtractImageFilter() {}

private:
  SubtractImageFilter(const Self&); //purposely not implemented
  void operator=(const Self&); //purposely not implemented


};

} // end namespace itk


#endif
