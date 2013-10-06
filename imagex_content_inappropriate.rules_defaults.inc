<?php
/**
 * @file
 * imagex_content_inappropriate.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function imagex_content_inappropriate_default_rules_configuration() {
  $items = array();
  $items['rules_imagex_inappropriate_content_comment'] = entity_import('rules_config', '{ "rules_imagex_inappropriate_content_comment" : {
      "LABEL" : "imagex_inappropriate_content_comment",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "inappropriate_content" ],
      "REQUIRES" : [ "flag", "rules" ],
      "ON" : [ "flag_flagged_inappropriate_content_comment" ],
      "DO" : [
        { "flag_fetch_comment_by_user" : {
            "USING" : {
              "flag" : "inappropriate_content_comment",
              "flagging_user" : [ "flagging_user" ]
            },
            "PROVIDE" : { "content_flagged_by_user" : { "content_flagged_by_user" : "Content flagged by user" } }
          }
        },
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "3" : "3" } },
            "subject" : "Comment flagged as inappropriate",
            "message" : "This is an automated message from [site:name] ([site:url])\\r\\n\\r\\nA comment has been flagged as inappropriate and requires review. The details are:\\r\\nComment flagged: [flagged-comment:title] ([flagged-comment:url])\\r\\nFlagged by: [flagging-user:name] ([flagging-user:url])\\r\\n",
            "from" : "[site:mail]"
          }
        }
      ]
    }
  }');
  $items['rules_imagex_inappropriate_content_node'] = entity_import('rules_config', '{ "rules_imagex_inappropriate_content_node" : {
      "LABEL" : "imagex_inappropriate_content_node",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "inappropriate_content" ],
      "REQUIRES" : [ "flag", "rules" ],
      "ON" : [ "flag_flagged_inappropriate_content_node" ],
      "DO" : [
        { "flag_fetch_node_by_user" : {
            "USING" : {
              "flag" : "inappropriate_content_node",
              "flagging_user" : [ "flagging_user" ]
            },
            "PROVIDE" : { "content_flagged_by_user" : { "content_flagged_by_user" : "Content flagged by user" } }
          }
        },
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "3" : "3" } },
            "subject" : "Content flagged as inappropriate",
            "message" : "This is an automated message from [site:name] ([site:url])\\r\\n\\r\\nAn item of content has been flagged as inappropriate and requires review. The details are:\\r\\nContent flagged: [flagged-node:title] ([flagged-node:url])\\r\\nFlagged by: [flagging-user:name] ([flagging-user:url])\\r\\n\\r\\n",
            "from" : "[site:mail]"
          }
        }
      ]
    }
  }');
  return $items;
}
