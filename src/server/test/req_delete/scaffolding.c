#include "license_pbs.h" /* See here for the software license */
#include <stdlib.h>
#include <stdio.h> /* sprintf */
#include <errno.h>

#include "pbs_job.h" /* all_jobs, job */
#include "server.h" /* server */
#include "array.h" /* job_array */
#include "batch_request.h" /* batch_request */
#include "attribute.h" /* pbs_attribute */
#include "work_task.h" /* work_task, all_tasks */
#include "queue.h" /* pbs_queue */
#include "node_func.h" /* node_info */

int check_and_resize(resizable_array *ra);
void update_next_slot(resizable_array *ra);
int lock_ji_mutex(job *pjob, const char *id, const char *msg, int logging);
int unlock_ji_mutex(job *pjob, const char *id, const char *msg, int logging);

#define MSG_LEN_LONG 160

const char *msg_deletejob = "Job deleted";
struct all_jobs alljobs;
const char *msg_delrunjobsig = "Job sent signal %s on delete";
struct server server;
const char *msg_manager = "%s at request of %s@%s";
int LOGLEVEL = 7; /* force logging code to be exercised as tests run */
long keep_seconds;
int  bad_queue;
int  bad_relay;
int  signal_issued;
int  nanny = 1;
int  br_freed;
int  alloc_work = 1;

batch_request *alloc_br(int type)
  {
  if (alloc_work)
    return((batch_request *)calloc(1, sizeof(batch_request)));
  else
    return(NULL);
  }

job_array *get_jobs_array(job **pjob)
  {
  fprintf(stderr, "The call to get_jobs_array needs to be mocked!!\n");
  exit(1);
  }

void account_record(int acctype, job *pjob, const char *text)
  {
  fprintf(stderr, "The call to acctype needs to be mocked!!\n");
  exit(1);
  }

int job_save(job *pjob, int updatetype, int mom_port)
  {
  fprintf(stderr, "The call to job_save needs to be mocked!!\n");
  exit(1);
  }

int svr_job_purge(job *pjob, int leaveSpoolFiles)
  {
  pjob->ji_qs.ji_state = JOB_STATE_COMPLETE;
  return(0);
  }

void chk_job_req_permissions(job **pjob_ptr, struct batch_request *preq)
  {
  fprintf(stderr, "The call to chk_job_req_permissions needs to be mocked!!\n");
  exit(1);
  }

void svr_mailowner(job *pjob, int mailpoint, int force, const char *text)
  {
  fprintf(stderr, "The call to svr_mailowner needs to be mocked!!\n");
  exit(1);
  }

long attr_ifelse_long(pbs_attribute *attr1, pbs_attribute *attr2, long deflong)
  {
  return(keep_seconds);
  }

void on_job_exit(struct work_task *ptask)
  {
  fprintf(stderr, "The call to on_job_exit needs to be mocked!!\n");
  exit(1);
  }

pbs_queue *get_jobs_queue(job **pjob)
  {
  static pbs_queue pque;

  pque.qu_qs.qu_type = QTYPE_Execution;

  if (bad_queue)
    return(NULL);
  else
    return(&pque);
  }

void reply_ack(struct batch_request *preq) {}

void free_nodes(job *pjob) 
  {
  pjob->ji_wattr[JOB_ATR_exec_host].at_val.at_str = NULL;
  }

void free_br(struct batch_request *preq)
  {
  br_freed = TRUE;
  }

struct work_task *set_task(enum work_type type, long event_id, void (*func)(struct work_task *), void *parm, int get_lock)
  {
  return(NULL);
  }

void req_reject(int code, int aux, batch_request *preq, const char *HostName, const char *Msg) { }


void delete_task(struct work_task *ptask) { }

int svr_chk_owner(struct batch_request *preq, job *pjob)
  {
  return(0);
  }

int job_abt(struct job **pjobp, const char *text)
  {
  if (pjobp != NULL)
    *pjobp = NULL;

  return(0);
  }

int issue_signal(job **pjob_ptr, const char *signame, void (*func)(struct batch_request *), void *extra, char *extend)
  {
  signal_issued = TRUE;
  return(PBSE_NONE);
  }

void set_resc_assigned(job *pjob, enum batch_op op) { }

void release_req(struct work_task *pwt) { }

char *pbse_to_txt(int err)
  {
  return(strdup("bob"));
  }

 work_task *next_task(all_tasks *at, int *iter)
  {
  fprintf(stderr, "The call to next_task needs to be mocked!!\n");
  exit(1);
  }

batch_request *cpy_stage(batch_request *preq, job *pjob, enum job_atr ati, int direction)
  {
  return((batch_request *)calloc(1, sizeof(batch_request)));
  }

int svr_setjobstate(job *pjob, int newstate, int newsubstate, int  has_queue_mute)
  {
  pjob->ji_qs.ji_state = newstate;
  pjob->ji_qs.ji_substate = newsubstate;
  return(0);
  }

job *svr_find_job(char *jobid, int get_subjob)
  {
  if (strcmp(jobid, "1.napali") == 0)
    {
    job *pjob = (job *)calloc(1, sizeof(job));
    strcpy(pjob->ji_qs.ji_jobid, jobid);
    pjob->ji_qs.ji_state = JOB_STATE_RUNNING;
    return(pjob);
    }

  return(NULL);
  }

int unlock_queue(struct pbs_queue *the_queue, const char *id, const char *msg, int logging)
  {
  return(0);
  }

void svr_evaljobstate(job *pjob, int *newstate, int *newsub, int forceeval)
  {
  fprintf(stderr, "The call to svr_evaljobstate needs to be mocked!!\n");
  exit(1);
  }

int insert_task(all_tasks *at, work_task *wt)
  {
  fprintf(stderr, "The call to insert_task needs to be mocked!!\n");
  exit(1);
  }

int get_svr_attr_l(int index, long *l)
  {
  if (nanny)
    *l = 1;

  return(0);
  }

batch_request *get_remove_batch_request(

  char *br_id)

  {
  return(NULL);
  }

int get_batch_request_id(

  batch_request *preq)

  {
  return(0);
  }

int unlock_ai_mutex(job_array *pa, const char *id, const char *msg, int logging)
  {
  return(0);
  }

void on_job_exit_task(struct work_task *ptask) {}

int enqueue_threadpool_request(void *(*func)(void *), void *arg)
  {
  return(0);
  }

void log_err(int l, const char *func_name, const char *msg) {}
void log_event(int type, int otype, const char *func_name, const char *msg) {}

int relay_to_mom(job **pjob_ptr, batch_request   *request, void (*func)(struct work_task *))
  {
  return(bad_relay);
  }

void traverse_all_jobs(void (*)(const char *, void*), void*)
{
}

void removeBeforeAnyDependencies(const char *)
{
}


/*
 * insert a new job into the array
 *
 * @param pjob - the job to be inserted
 * @return PBSE_NONE on success 
 */
int insert_job(

  struct all_jobs *aj,
  job             *pjob)

  {
  int rc = -1;

  if (aj == NULL)
    {
    rc = PBSE_BAD_PARAMETER;
    log_err(rc,__func__,"null job array input");
    return(rc);
    }
  if (pjob == NULL)
    {
    rc = PBSE_BAD_PARAMETER;
    log_err(rc,__func__,"null job input");
    return(rc);
    }

  pthread_mutex_lock(aj->alljobs_mutex);

  rc = insert_thing(aj->ra,pjob);
  if (rc == -1)
    {
    rc = ENOMEM;
    log_err(rc, __func__, "No memory to resize the array...SYSTEM FAILURE\n");
    }
  else
    {
    add_hash(aj->ht, rc, pjob->ji_qs.ji_jobid);
    rc = PBSE_NONE;
    }

  pthread_mutex_unlock(aj->alljobs_mutex);

  return(rc);
  } /* END insert_job() */


/*
 * inserts an item, resizing the array if necessary
 *
 * @return the index in the array or -1 on failure
 */
int insert_thing(

  resizable_array *ra,
  void             *thing)

  {
  int rc;

  /* check if the array must be resized */
  if ((rc = check_and_resize(ra)) != PBSE_NONE)
    {
    return(-1);
    }

  ra->slots[ra->next_slot].item = thing;

  /* save the insertion point */
  rc = ra->next_slot;

  /* handle the backwards pointer, next pointer is left at zero */
  ra->slots[rc].prev = ra->last;

  /* make sure the empty slot points to the next occupied slot */
  if (ra->last == ALWAYS_EMPTY_INDEX)
    {
    ra->slots[ALWAYS_EMPTY_INDEX].next = rc;
    }

  /* update the last index */
  ra->slots[ra->last].next = rc;
  ra->last = rc;

  /* update the new item's next index */
  ra->slots[rc].next = ALWAYS_EMPTY_INDEX;

  /* increase the count */
  ra->num++;

  update_next_slot(ra);

  return(rc);
  } /* END insert_thing() */


/* initializes the all_jobs array */
void initialize_all_jobs_array(

  struct all_jobs *aj)

  {
  if (aj == NULL)
    {
    log_err(PBSE_BAD_PARAMETER,__func__,"null input job array");
    return;
    }

  aj->ra = initialize_resizable_array(INITIAL_JOB_SIZE);
  aj->ht = create_hash(INITIAL_HASH_SIZE);

  aj->alljobs_mutex = (pthread_mutex_t*)calloc(1, sizeof(pthread_mutex_t));
  pthread_mutex_init(aj->alljobs_mutex, NULL);
  } /* END initialize_all_jobs_array() */


/*
 * checks if the array needs to be resized, and resizes if necessary
 *
 * @return PBSE_NONE or ENOMEM
 */
int check_and_resize(

    resizable_array *ra)

  {
  slot        *tmp;
  size_t       remaining;
  size_t       size;

  if (ra->max == ra->num + 1)
    {
    /* double the size if we're out of space */
    size = (ra->max * 2) * sizeof(slot);

    if ((tmp = (slot *)realloc(ra->slots,size)) == NULL)
      {
      return(ENOMEM);
      }

    remaining = ra->max * sizeof(slot);

    memset(tmp + ra->max, 0, remaining);

    ra->slots = tmp;

    ra->max = ra->max * 2;
    }

  return(PBSE_NONE);
  } /* END check_and_resize() */


/* 
 * updates the next slot pointer if needed \
 */
void update_next_slot(

    resizable_array *ra) /* M */

  {
  while ((ra->next_slot < ra->max) &&
      (ra->slots[ra->next_slot].item != NULL))
    ra->next_slot++;
  } /* END update_next_slot() */


job *next_job(

  struct all_jobs *aj,
  int             *iter)

  {
  job *pjob;

  if (aj == NULL)
    {
    log_err(PBSE_BAD_PARAMETER, __func__, "null input pointer to all_jobs struct");
    return(NULL);
    }
  if (iter == NULL)
    {
    log_err(PBSE_BAD_PARAMETER, __func__, "null input iterator");
    return(NULL);
    }

  pthread_mutex_lock(aj->alljobs_mutex);

  pjob = (job *)next_thing(aj->ra,iter);

  pthread_mutex_unlock(aj->alljobs_mutex);

  if (pjob != NULL)
    {
    lock_ji_mutex(pjob, __func__, NULL, LOGLEVEL);

    if (pjob->ji_being_recycled == TRUE)
      {
      unlock_ji_mutex(pjob, __func__, "1", LOGLEVEL);

      pjob = next_job(aj,iter);
      }
    }

  return(pjob);
  } /* END next_job() */

int lock_ji_mutex(

  job        *pjob,
  const char *id,
  const char *msg,
  int        logging)

  {
  int rc = PBSE_NONE;
  char *err_msg = NULL;
  char stub_msg[] = "no pos";

  if (logging >= 10)
    {
    err_msg = (char *)calloc(1, MSG_LEN_LONG);
    if (msg == NULL)
      msg = stub_msg;
    snprintf(err_msg, MSG_LEN_LONG, "locking %s in method %s-%s", pjob->ji_qs.ji_jobid, id, msg);
    log_record(PBSEVENT_DEBUG, PBS_EVENTCLASS_NODE, id, err_msg);
    }

  if (pjob->ji_mutex != NULL)
    {
    if (pthread_mutex_lock(pjob->ji_mutex) != 0)
      {
      if (logging >= 20)
        {
        snprintf(err_msg, MSG_LEN_LONG, "ALERT: cannot lock job %s mutex in method %s",
                                     pjob->ji_qs.ji_jobid, id);
        log_record(PBSEVENT_DEBUG, PBS_EVENTCLASS_NODE, id, err_msg);
        }
      rc = PBSE_MUTEX;
      }
    }
  else
    {
    rc = -1;
    log_err(rc, __func__, "Uninitialized mutex pass to pthread_mutex_lock!");
    }

  if (err_msg != NULL)
  free(err_msg);

  return rc;
  }


int unlock_ji_mutex(

  job        *pjob,
  const char *id,
  const char *msg,
  int        logging)

  {
  int rc = PBSE_NONE;
  char *err_msg = NULL;
  char stub_msg[] = "no pos";

  if (logging >= 10)
    {
    err_msg = (char *)calloc(1, MSG_LEN_LONG);
    if (msg == NULL)
      msg = stub_msg;
    snprintf(err_msg, MSG_LEN_LONG, "unlocking %s in method %s-%s", pjob->ji_qs.ji_jobid, id, msg);
    log_record(PBSEVENT_DEBUG, PBS_EVENTCLASS_NODE, id, err_msg);
    }

  if (pjob->ji_mutex != NULL)
    {
    if (pthread_mutex_unlock(pjob->ji_mutex) != 0)
      {
    if (logging >= 20)
        {
        snprintf(err_msg, MSG_LEN_LONG, "ALERT: cannot unlock job %s mutex in method %s",
                                            pjob->ji_qs.ji_jobid, id);
        log_record(PBSEVENT_DEBUG, PBS_EVENTCLASS_NODE, id, err_msg);
        }
      rc = PBSE_MUTEX;
      }
    }
  else
    {
    rc = -1;
    log_err(rc, __func__, "Uninitialized mutex pass to pthread_mutex_unlock!");
    }

   if (err_msg != NULL)
     free(err_msg);

   return rc;
   }

void log_record(

  int         eventtype,  /* I */
  int         objclass,   /* I */
  const char *objname,    /* I */
  const char *text)       /* I */

  {
  return;
  }

ssize_t read_ac_socket(int fd, void *buf, ssize_t count)
  {
  return(0);
  }

ssize_t write_ac_socket(int fd, const void *buf, ssize_t count)
  {
  return(0);
  }
