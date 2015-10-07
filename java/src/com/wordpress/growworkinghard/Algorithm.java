/*
 * The MIT License
 *
 * Copyright 2015 francesco.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
package com.wordpress.growworkinghard;

/**
 * @brief Algorithm interface based on Strategy Pattern
 * This interface allows to use several type of algorithms independently from
 * the data type.
 *
 * @author sidereus
 * @date 2015-10-03
 */
public interface Algorithm<T> {

    /**
     * @brief Implementation of the algorithm
     *
     * @return the position of the searched element
     */
    public int rank();

    /**
     * @brief Parameters setter
     *
     * @param i_vec the array to process
     * @param key   the element to find
     * @param lo    lower bound
     * @param hi    upper bound
     */
    public void setParam(final T[] i_vec, final T key, final int lo, final int hi);

}
