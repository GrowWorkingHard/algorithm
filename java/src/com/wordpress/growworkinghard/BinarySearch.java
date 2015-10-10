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

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * @brief This class run the Binary Search algorithm
 * It allows to analyze a sorted array looking for a key value. You can set a
 * lower and an upper bound if you know that the searched key is in a specified
 * part of the array.
 *
 * @author sidereus
 * @date 2015-10-03
 */
public class BinarySearch<T extends Comparable<T>> implements Algorithm<T> {

    private T[] i_vec; //!< input sorted array 
    private T key; //!< the element to search
    private int lo; //!< the lower bound of the array
    private int hi; //!< the upper bound of the array
    private boolean setParam = false;
    private final Logger logger =
        Logger.getLogger(BinarySearch.class.getName());

    /**
     * @brief Default constructor
     */
    public BinarySearch() {}

    /**
     * @brief Constructor to use if you already have the sorted vector and key
     *        The lower bound and upper bound are respectively set to 0 and the
     *        length of the array.
     *
     * @param i_vec
     *            input array containing the data to analyze
     * @param key
     *            the element to search
     * @exception NullPointerException
     *                if a param is null
     */
    public BinarySearch(final T[] i_vec, final T key) {
    
        if (i_vec == null)
            throw new NullPointerException("The input vector cannot be null");

        if (key == null)
            throw new NullPointerException("The input key cannot be null");

        this.i_vec = i_vec;
        this.key = key;

        this.lo = 0;
        this.hi = i_vec.length;

        setParam = true;

    }

    /**
     * @brief Constructor to use if you know everything
     *
     * @param i_vec
     *            input array containing the data to analyze
     * @param key
     *            the element to search
     * @param lo
     *            the lower bound
     * @param hi
     *            the upper bound
     */
    public BinarySearch(final T[] i_vec, final T key, final int lo, final int hi) {

        validateState(i_vec, key, lo, hi);

        this.i_vec = i_vec;
        this.key = key;
        this.lo = lo;
        this.hi = hi;

        setParam = true;

    }

    /**
     * {@inheritDoc}
     *
     * @see Algorithm#rank()
     */
    public int rank() {
    
        if (setParam) {
            return rank(i_vec, key, lo, hi);
        } else {
            logger.log(Level.SEVERE, "Parameters are not set");
            return -1;
        }

    }

    /**
     * {@inheritDoc}
     *
     * @see Algorithm#setParam(T[],T,int,int)
     */
    public void setParam(final T[] i_vec, final T key, final int lo, final int hi) {

        validateState(i_vec, key, lo, hi);

        this.i_vec = i_vec;
        this.key = key;
        this.lo = lo;
        this.hi = hi;

        setParam = true;

    }

    /**
     * @brief the binary search algorithm with recursion call
     *
     * @param i_vec
     *            input array containing the data to analyze
     * @param key
     *            the element to search
     * @param lo
     *            the lower bound
     * @param hi
     *            the upper bound
     * @return the position of the searched element (<code>-1</code> if no element found)
     */
    private int rank(final T[] i_vec, final T key, final int lo, final int hi) {

        if (lo > hi) { // the key is not present in the array

           logger.log(Level.INFO, "No {0} found", key);
           setParam = false;
           return -1;

        } else {

            // get the position at the half of the array
            int m = (int) Math.floor((lo + hi)/2);

            int cmp = i_vec[m].compareTo(key);

            if (cmp == 0) { // element found

                setParam = false;
                return m;

            } else if (cmp < 0) { // element smaller than key

                m += 1;
                return rank(i_vec, key, m, hi);

            } else { // element bigger than key

                m -= 1;
                return rank(i_vec, key, lo, m);

            }

        }
    }

    /**
     * @brief This method is useful to validate the method arguments
     *
     * @param i_vec
     *            input array containing the data to analyze
     * @param key
     *            the element to search
     * @param lo
     *            the lower bound
     * @param hi
     *            the upper bound
     * @exception NullPointerException
     *                the exception is thrown if:
     *                <ul>
     *                <li>the input vector <tt>i_vec</tt> is
     *                <code>null</code></li>
     *                <li><tt>key</tt> is <code>null</code></li>
     *                </ul>
     * @exception IllegalArgumentException
     *                the exception is thrown if:
     *                <ul>
     *                <li>the lower bound <tt>lo</tt> is less than <code>0</code></li>
     *                <li>the upper bound <tt>hi</tt> is greater than <code>i_vec.length</code></li>
     *                </ul>
     */
    private void validateState(final T[] i_vec, final T key, final int lo, final int hi) {

        if (i_vec == null)
            throw new NullPointerException("The input vector cannot be null");

        if (key == null)
            throw new NullPointerException("The input key cannot be null");

        if (lo < 0)
            throw new IllegalArgumentException(lo + "is less than 0");

        if (hi > i_vec.length)
            throw new IllegalArgumentException(hi + "is greater than the length of the input vector");

    }

    public static void main(String[] args) {

        Character[] test = new Character[5];
        test[0] = 'c';
        test[1] = 'd';
        test[2] = 'g';
        test[3] = 'k';
        test[4] = 's';

        System.out.println(test.toString());
        System.out.println("First test: looking for key g"); 
        Algorithm<Character> binsearch = new BinarySearch<Character>(test, 'g', 0, test.length);
        int pos = binsearch.rank();
        System.out.println(pos);

        pos = binsearch.rank();

        binsearch.setParam(test, 'd', 2, test.length);
        pos = binsearch.rank();
        System.out.println(pos);
 
        binsearch.setParam(test, 'd', 0, test.length/2);
        pos = binsearch.rank();
        System.out.println(pos);

        System.exit(0);

    }

}
