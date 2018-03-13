/*! @file OIDAuthState+Mac.h
    @brief AppAuth iOS SDK
    @copyright
        Copyright 2016 Google Inc. All Rights Reserved.
    @copydetails
        Licensed under the Apache License, Version 2.0 (the "License");
        you may not use this file except in compliance with the License.
        You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
 */

#import "OIDAuthState.h"

NS_ASSUME_NONNULL_BEGIN

/*! @brief macOS specific convenience methods for @c OIDAuthState.
 */
@interface OIDAuthState (Mac)

/*! @brief Convenience method to create a @c OIDAuthState by presenting an authorization request
        and performing the authorization code exchange in the case of code flow requests.
    @param authorizationRequest The authorization request to present.
    @param callback The method called when the request has completed or failed.
    @return A @c OIDExternalUserAgentSession instance which will terminate when it
        receives a @c OIDExternalUserAgentSession.cancel message, or after processing a
        @c OIDExternalUserAgentSession.resumeExternalUserAgentFlowWithURL: message.
 */
+ (id<OIDExternalUserAgentSession, OIDAuthorizationFlowSession>)
    authStateByPresentingAuthorizationRequest:(OIDAuthorizationRequest *)authorizationRequest
                                     callback:(OIDAuthStateAuthorizationCallback)callback;

/*! @brief Presents a RP-initiated logout using the external user agent.
    @param endSessionRequest The end session request to present.
    @param callback The method called when the request has completed or failed.
    @return A @c OIDExternalUserAgentSession instance which will terminate when it receives a
        @c OIDExternalUserAgentSession.cancel message, or after processing a
        @c OIDExternalUserAgentSession.resumeExternalUserAgentFlowWithURL: message.
    @discussion Afer a successful ending of the session, it invalidates the @c OIDAuthState.
        Remove references to this instance. Hence, a new authorization flow is required
        to retrieve a new instance of @c OIDAuthState.
    @see http://openid.net/specs/openid-connect-session-1_0.html#RPLogout
 */
- (id<OIDExternalUserAgentSession>)presentEndSessionRequest:(OIDEndSessionRequest *)endSessionRequest
                                                   callback:(OIDEndSessionCallback)callback;

@end

NS_ASSUME_NONNULL_END
