/**
 * Copyright (c) 2016-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <Foundation/Foundation.h>

#import <IGListKit/IGListMacros.h>

@class IGListSectionController;
@protocol IGListSectionType;

NS_ASSUME_NONNULL_BEGIN

/**
 The IGListSectionMap provides a way to map a collection of objects to a collection of section controllers and achieve
 constant-time lookups O(1).

 IGListSectionMap is a mutable object and does not garauntee thread safety.
 */
IGLK_SUBCLASSING_RESTRICTED
@interface IGListSectionMap : NSObject <NSCopying>

- (instancetype)initWithMapTable:(NSMapTable *)mapTable NS_DESIGNATED_INITIALIZER;

/**
 The objects stored in the map.
 */
@property (nonatomic, strong, readonly) NSArray *objects;

/**
 Update the map with objects and the section controller counterparts.

 @param objects            The objects in the collection.
 @param sectionControllers The section controllers that map to each object.
 */
- (void)updateWithObjects:(NSArray <id <NSObject>> *)objects sectionControllers:(NSArray <id <NSObject>> *)sectionControllers;

/**
 Fetch a section controller given a section.

 @param section The section index of the section controller.

 @return A section controller.
 */
- (nullable IGListSectionController <IGListSectionType> *)sectionControllerForSection:(NSUInteger)section;

/**
 Fetch the object for a section

 @param section The section index of the object.

 @return The object corresponding to the section.
 */
- (id)objectForSection:(NSUInteger)section;

/**
 Fetch a section controller given an object. Can return nil.

 @param object The object that maps to a section controller.

 @return A section controller.
 */
- (nullable id)sectionControllerForObject:(id)object;

/**
 Look up the section index for a section controller.

 @param sectionController The list to look up.

 @return The section index of the given section controller if it exists, NSNotFound otherwise.
 */
- (NSUInteger)sectionForSectionController:(id)sectionController;

/**
 Look up the section index for an object.

 @param object The object to look up.

 @return The section index of the given object if it exists, NSNotFound otherwise.
 */
- (NSUInteger)sectionForObject:(id)object;

/**
 Remove all saved objects and section controllers.
 */
- (void)reset;

/**
 Update an object with a new instance.
 */
- (void)updateObject:(id)object;

/**
 Applies a given block object to the entries of the section controller map.

 @param block A block object to operate on entries in the section controller map.
 */
- (void)enumerateUsingBlock:(void (^)(id object, IGListSectionController<IGListSectionType> *sectionController, NSUInteger section, BOOL *stop))block;

- (id)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
